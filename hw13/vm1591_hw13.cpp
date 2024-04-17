#include <iostream>
#include <vector>
using namespace std;

const int GRID_DIM = 20;
const int INIT_DOODLEBUG_POP = 5;
const int INIT_ANT_POP = 100;
const int ANT_REPRODUCE = 3;
const int DOODLEBUG_REPRODUCE = 8;
const int MAX_DAYS_WITHOUT_EATING = 3;

class Organism {
    protected:
        int row;
        int col;
        int daysUntilBreeding;
    public:
        Organism(){};
        Organism(int row, int col, int daysUntilBreeding) {
            this->row=row;
            this->col=col;
            this-> daysUntilBreeding = daysUntilBreeding;
        };
        int getDaysUntilBreeding() {
            return daysUntilBreeding;
        }
        virtual void move(char**& world){};

        friend bool operator==(const Organism& bug1, const Organism& bug2){
            return bug1.col == bug2.col && bug1.row == bug2.row;
        };

        friend ostream& operator<<(ostream& outs, const Organism& bug){
            outs << "(" << bug.row << ", " << bug.col << ")";
            return outs;
        };

        void getNextCoordinate(char**& world, int& row, int& col, int worldSize) {
            vector<int> openSpaceArr;
            // left
            if (col > 0 && world[row][col - 1] == '-') openSpaceArr.push_back(0);
            // right
            if (col + 1 < worldSize && world[row][col + 1] == '-') openSpaceArr.push_back(1);
            // up
            if (row > 0 && world[row - 1][col] == '-') openSpaceArr.push_back(2);
            // down
            if (row + 1 < worldSize && world[row + 1][col] == '-') openSpaceArr.push_back(3);

            if (openSpaceArr.size() > 0) {
                // generate random number from 0-3 until we find an empty adjacent space
                srand(time(0));
                int move = openSpaceArr[rand() % openSpaceArr.size()];
                switch (move) {
                    // case 0: move left
                    case 0:
                        col--;
                        break;
                    // case 1: move right
                    case 1:
                        col++;
                        break;
                    // case 2: move up
                    case 2:
                        row--;
                        break;
                    // case 3: move down
                    case 3:
                        row++;
                        break;
                }
            }
        }
};
class Ant: public Organism { 
    public:
        Ant(){};
        Ant(int row, int col): Organism(row, col, ANT_REPRODUCE){};

        void move(char**& world){
            int newRow = row;
            int newCol = col;
            this->getNextCoordinate(world, newRow, newCol, GRID_DIM);
            // overwrite the current coordinate with empty space
            world[row][col] = '-';
            // overwrite the new coordinate with o
            world[newRow][newCol] = 'o';
            // set new coordinates
            row = newRow;
            col = newCol;
            // decrement days until breeding if not already 0
            if (daysUntilBreeding > 0) {
                daysUntilBreeding = daysUntilBreeding - 1;
            }
        }
        void reproduce(char**& world, vector<Ant>& antV) {
            int newRow = row;
            int newCol = col;
            getNextCoordinate(world, newRow, newCol, GRID_DIM);
            // if there's space create new ant
            if (!(newRow == row && newCol == col)){
                // set parents daysUntilBreeding back
                this->daysUntilBreeding = ANT_REPRODUCE;
                // overwrite the new coordinate with o
                world[newRow][newCol] = 'o';
                // push new ant into vector with new coordinates
                Ant ant(newRow, newCol);
                antV.push_back(ant);
            }
        }
};
class Doodlebug: public Organism {
    int daysLeftToEat; 
    public:
        Doodlebug(){};
        Doodlebug(int row, int col): Organism(row, col, DOODLEBUG_REPRODUCE){
            this->daysLeftToEat=MAX_DAYS_WITHOUT_EATING;
        };

        int getDaysLeftToEat(){
            return daysLeftToEat;
        }

        void removeBug(vector<Ant>&v, Ant a){
            int j = 0;
            for (int i = 0; i < v.size(); i++) {
                if (!(v[i] == a)) v[j++] = v[i];
            }
            v.resize(j);
        }

        void getPreyCoordinate(char**& world, int& row, int& col, int worldSize){
            vector<int> preyArr;
            // left
            if (col > 0 && world[row][col - 1] == 'o') preyArr.push_back(0);
            // right
            if (col + 1 < worldSize && world[row][col + 1] == 'o') preyArr.push_back(1);
            // up
            if (row > 0 && world[row - 1][col] == 'o') preyArr.push_back(2);
            // down
            if (row + 1 < worldSize && world[row + 1][col] == 'o') preyArr.push_back(3);

            if (preyArr.size() > 0) {
                // generate random number from 0-3 until we find an empty adjacent space
                srand(time(0));
                int move = preyArr[rand() % preyArr.size()];
                switch (move) {
                    // case 0: move left
                    case 0:
                        col--;
                        break;
                    // case 1: move right
                    case 1:
                        col++;
                        break;
                    // case 2: move up
                    case 2:
                        row--;
                        break;
                    // case 3: move down
                    case 3:
                        row++;
                        break;
                }
            }
        };

        void reproduce(char**& world, vector<Doodlebug>& dbV) {
            int newRow = row;
            int newCol = col;
            getNextCoordinate(world, newRow, newCol, GRID_DIM);
            // if there's space create new ant
            if (!(newRow == row && newCol == col)){
                // set parent's daysUntilBreeding back
                this->daysUntilBreeding = DOODLEBUG_REPRODUCE;
                // overwrite the new coordinate with X
                world[newRow][newCol] = 'X';
                // push new doodlebug into vector with new coordinates
                Doodlebug db(newRow, newCol);
                dbV.push_back(db);
            }
        };

        void die(char**& world){
            // overwrite current coordinate with - for empty space
            world[row][col] = '-';
        }

        void move(char**& world, vector<Ant>& antV, vector<Doodlebug>& dbV){
            int newRow = row;
            int newCol = col;
            this->getPreyCoordinate(world, newRow, newCol, GRID_DIM);
            // if no prey was detected -> randomly move L/R/U/D
            if (newRow == row && newCol == col) {
                this->getNextCoordinate(world, newRow, newCol, GRID_DIM);
                daysLeftToEat--;
            } else { // otherwise eat ant 
                this->removeBug(antV, Ant(newRow, newCol));
                daysLeftToEat = MAX_DAYS_WITHOUT_EATING;
            }
            world[row][col] = '-';
            // overwrite the new coordinate with X
            world[newRow][newCol] = 'X';
            // set new coordinates
            row = newRow;
            col = newCol;
            // decrement daysUntilBreeding if not already 0
            if (daysUntilBreeding > 0) daysUntilBreeding--;
        };
};

void initializeWorld(char**& world, vector<Doodlebug>& doodlebugV, vector<Ant>& antV);
void printWorld(char** world);
void killOffDoodles(char**& world, vector<Doodlebug>& doodleV);

int main(){
    string x;
    int time = 0;
    char** world = new char*[GRID_DIM];
    for( int i = 0 ; i < GRID_DIM ; i++ ) {
        world[i] = new char[GRID_DIM];
    }
    vector<Doodlebug> doodlebugV;
    vector<Ant> antV;
    Doodlebug* dPtr;
    Ant* aPtr;

    while(true) {
        cout << "World at time " << time << ":\n" << endl;
        if (time == 0) initializeWorld(world, doodlebugV, antV);
        else {
            int dbSize = doodlebugV.size();
            for (int i = 0; i < dbSize; i++) {
                dPtr = &doodlebugV[i];
                dPtr->move(world, antV, doodlebugV);
            }
            killOffDoodles(world, doodlebugV);
            for (int i = 0; i < dbSize; i++) {
                if (dPtr->getDaysUntilBreeding() == 0) {
                    dPtr->reproduce(world, doodlebugV);
                }
            }
            int aSize = antV.size();
            for (int i = 0; i < aSize; i++) {
                aPtr = &antV[i];
                aPtr->move(world);
                if (aPtr->getDaysUntilBreeding() == 0) {
                    aPtr->reproduce(world, antV);
                }
            } 
        }
        printWorld(world);
        time++;
        cout << "Press ENTER to continue" << endl;
        getline(cin, x);
        dPtr = nullptr;
        aPtr = nullptr;
    }
    delete dPtr;
    delete aPtr;
    for (int i = 0; i < GRID_DIM; i++) {
        world[i] = nullptr;
        delete[] world[i];
    } delete[] world;
    return 0;
}

void killOffDoodles(char**& world, vector<Doodlebug>& doodleV){
    vector<Doodlebug> temp;
    for (Doodlebug d : doodleV) {
        if (d.getDaysLeftToEat() > 0) {
            temp.push_back(d);
        } else {
            d.die(world);
        }
    }
    doodleV = temp;
}


// populate world with 5 doodle bugs(X) + 100 ants(o)
void initializeWorld(char**& world, vector<Doodlebug>& doodlebugV, vector<Ant>& antV) {
    srand(time(0));
    for (int i = 0; i < GRID_DIM; i++){
        for (int j = 0; j < GRID_DIM; j++) {
            world[i][j] = '-';
        }
    }
    int row, col;
    for (int i = 0; i < INIT_DOODLEBUG_POP; i++) {
        do {
            // generate 2 random #s from 0 - 19
            row = rand() % GRID_DIM;
            col = rand() % GRID_DIM;
        } // as long as world vector is occupied at that index, keep generating new number
        while (world[row][col] != '-');
        // set element at index to X for doodlebug
        world[row][col] = 'X';
        // create a doodlebug object with x and y + push it to doodlebugs vector
        Doodlebug bug(row, col);
        doodlebugV.push_back(bug);
    }
    for (int i = 0; i < INIT_ANT_POP; i++) {
        do {
            // generate 2 random #s from 0 - 19
            row = rand() % GRID_DIM;
            col = rand() % GRID_DIM;
        } // as long as world vector is occupied at that index, keep generating new number
        while (world[row][col] != '-');
        // set element at index to o for ant
        world[row][col] = 'o';
        // create an ant object with x and y + push it to ants vector
        Ant bug(row, col);
        antV.push_back(bug);
    }
}

void printWorld(char** world) {
    for (int i = 0; i < GRID_DIM; i++) {
        for (int j = 0; j < GRID_DIM; j++) {
            cout << world[i][j] << " ";
        }
        cout << endl;
    } cout << endl;
}
