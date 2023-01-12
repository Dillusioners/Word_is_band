/*
	Author: LeeTuah
	Type: Normal League Event
	Date: January 12 2023
*/

# include <iostream>
# include <ctime>

void fillArray(int v[30][30], int max_size, int filler){
	for(int i = 0; i != max_size; i++){
		for(int j = 0; j != max_size; j++){
			v[i][j] = filler;
		}
	}
}

int emptyCount(int v[30][30]){
	int count = 0;
	for(int i = 0; i != 30; i++){
		for(int j = 0; j != 30; j++){
			if(v[i][j] == 0) count++;
		}
	}
	return count;
}

void printArray(int v[30][30]){
	for(int i = 0; i != 30; i++){
		for(int j = 0; j != 30; j++){
			std::cout << v[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void bellRing(int v[30][30]){
	srand(time(NULL));
	bool checkAllCorners, hittingCorners;
	int randPos;

	for(int i = 0; i != 30; i++){
		for(int j = 0; j != 30; j++){
			// if there is no flea in the index then skip
			if(v[i][j] == 0) continue;

			checkAllCorners = ((i > 0 && i < 29) && (j > 0 && j < 29));
			hittingCorners = ((i == 0 && j == 0) || (i == 29 && j == 29) || (i == 0 && j == 29) || (i == 29 && j == 0));

			// checking if it is possible to move in 4 directions
			if(checkAllCorners){
				randPos = (rand() % 4) + 1;
				switch(randPos){
					case 1: // up
						v[i - 1][j] += 1;
						break;

					case 2: // right
						v[i][j + 1] += 1;
						break;

					case 3: // down
						v[i + 1][j] += 1;
						break;

					case 4: // left
						v[i][j - 1] += 1;
						break;
				}
				v[i][j]--;
			}
      
      // checks if a corner is hit
			else if(hittingCorners){
				randPos = (rand() % 2) + 1;
				switch(randPos){
					case 1: // up or down
						v[i + ((i == 0)? 1 : -1)][j] += 1;
						break;

					case 2: // left or right
						v[i][j + ((j == 0)? 1 : -1)] += 1;
				}
			}
			else{
				randPos = (rand() % 3) + 1;
				switch(randPos){
					case 1: // up or down
						v[i + ((i == 0)? 1 : -1)][j] += 1;
						break;

					case 2: // left or right
						v[i][j + ((j == 0)? 1 : -1)] += 1;

					case 3:
						if(i == 0 || i == 29){
							v[i][j + (((rand() % 2) + 1 == 1)? 1 : -1)] += 1;
						}
						else if(j == 0 || j == 29){
							v[i + (((rand() % 2) + 1 == 1)? 1 : -1)][j] += 1;
						}
				}
			}
		}
	}
}

// main method where all stuff is done
int main(int argc, char const *argv[]){
	short answer, i;	
	int grid[30][30];

	fillArray(grid, 30, 1);

	std::cout << "Flea grid before bell rung: \n";
	printArray(grid);

	for(i = 0; i != 50; i++){
		bellRing(grid);
	}

	std::cout << "Flea grid after bell rung: \n";
	printArray(grid);

	answer = emptyCount(grid);

	std::cout << "Total squares empty: " << answer << '\n';
	std::cout << "In Percentage: " << (answer/9.00) << "%\n";

	return 0;
}
