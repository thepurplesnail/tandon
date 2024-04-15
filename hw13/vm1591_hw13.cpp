#include <iostream>
#include <vector>
using namespace std;

const int GRID_DIM = 10;
const int INIT_DOODLEBUG_POP = 10;
const int INIT_ANT_POP = 2;
const int ANT_REPRODUCE = 3;
const int DOODLEBUG_REPRODUCE = 8;

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
    public:
        Doodlebug(){};
        Doodlebug(int row, int col): Organism(row, col, DOODLEBUG_REPRODUCE){};

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

        void move(char**& world){
            int newRow = row;
            int newCol = col;
            this->getPreyCoordinate(world, newRow, newCol, GRID_DIM);
            if (newRow == row && newCol == col) {
                this->getNextCoordinate(world, newRow, newCol, GRID_DIM);
            }
            world[row][col] = '-';
            // overwrite the new coordinate with X
            world[newRow][newCol] = 'X';
            // set new coordinates
            row = newRow;
            col = newCol;
        }

        // void reproduce(char**& world) {

        // }
};

void initializeWorld(char**& world, vector<Doodlebug>& doodlebugV, vector<Ant>& antV);
void printWorld(char** world);

int main(){
    string x;
    int time = 0;
    char** world = new char*[GRID_DIM];
    for( int i = 0 ; i < GRID_DIM ; i++ ) {
        world[i] = new char[GRID_DIM];
    }
    vector<Doodlebug> doodlebugV;
    vector<Ant> antV;
    while(true) {
        cout << "World at time " << time << ":\n" << endl;
        if (time == 0) initializeWorld(world, doodlebugV, antV);
        else {
            int doodlebugVSize = doodlebugV.size();
            for (int i = 0; i < doodlebugVSize; i++) {
                Doodlebug* dPtr = &doodlebugV[i];
                dPtr->move(world);
            }
            int antVSize = antV.size();
            for (int i = 0; i < antVSize; i++) {
                Ant* aPtr = &antV[i];
                aPtr->move(world);
                if (aPtr->getDaysUntilBreeding() == 0) {
                    aPtr->reproduce(world, antV);
                }
            } 
        }
        cout << "ant vector size: " << antV.size() << endl;
        cout << "doodlebug vector size: " << doodlebugV.size() << endl;
        printWorld(world);
        time++;
        cout << "Press ENTER to continue" << endl;
        getline(cin, x);
    }
    for (int i = 0; i < GRID_DIM; i++) {
        world[i] = nullptr;
        delete[] world[i];
    } delete[] world;
    return 0;
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
        // set element at index to X for doodlebug
        world[row][col] = 'o';
        // create a doodlebug object with x and y + push it to doodlebugs vector
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
