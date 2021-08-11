#include<iostream>

using namespace std;

bool matchGoal(int puzz[9]) {
	/*if (puzz[0] == 1 && puzz[1] == 2 && puzz[2] == 3 && puzz[3] == 4 && puzz[4] == -1 && puzz[5] == 5 && puzz[6] == 6 && puzz[7] == 7 && puzz[8] == 8)
		return true;*/
	if (puzz[0] == 1 && puzz[1] == 2 && puzz[2] == 3 && puzz[3] == 8 && puzz[4] == 0 && puzz[5] == 4 && puzz[6] == 7 && puzz[7] == 6 && puzz[8] == 5)
		return true;
	return false;
}

int* up(int puzz[9]){
	
	if (puzz[0] == 0 || puzz[1] == 0 || puzz[2] == 0) {
		return nullptr;
	}
	else if (puzz[3] == 0) {
		puzz[3] = puzz[0];
		puzz[0] = 0;
	}
	else if (puzz[4] == 0) {
		puzz[4] = puzz[1];
		puzz[1] = 0;
	}
	else if (puzz[5] == 0) {
		puzz[5] = puzz[2];
		puzz[2] = 0;
	}
	else if (puzz[6] == 0) {
		puzz[6] = puzz[3];
		puzz[3] = 0;
	}
	else if (puzz[7] == 0) {
		puzz[7] = puzz[4];
		puzz[4] = 0;
	}
	else if (puzz[8] == 0) {
		puzz[8] = puzz[5];
		puzz[5] = 0;
	}
	return puzz;
}

int* down(int puzz[9]) {
	
	if (puzz[6] == 0 || puzz[7] == 0 || puzz[8] == 0) {
		return nullptr;
	}
	else if (puzz[0] == 0) {
		puzz[0] = puzz[3];
		puzz[3] = 0;
	}
	else if (puzz[1] == 0) {
		puzz[1] = puzz[4];
		puzz[4] = 0;
	}
	else if (puzz[2] == 0) {
		puzz[2] = puzz[5];
		puzz[5] = 0;
	}
	else if (puzz[3] == 0) {
		puzz[3] = puzz[6];
		puzz[6] = 0;
	}
	else if (puzz[4] == 0) {
		puzz[4] = puzz[7];
		puzz[7] = 0;
	}
	else if (puzz[5] == 0) {
		puzz[5] = puzz[8];
		puzz[8] = 0;
	}
	return puzz;
}
int* right(int puzz[9]) {
	
	if (puzz[2] == 0 || puzz[5] == 0 || puzz[8] == 0) {
		return nullptr;
	}
	else if (puzz[0] == 0) {
		puzz[0] = puzz[1];
		puzz[1] = 0;
	}
	else if (puzz[1] == 0) {
		puzz[1] = puzz[2];
		puzz[2] = 0;
	}
	else if (puzz[3] == 0) {
		puzz[3] = puzz[4];
		puzz[4] = 0;
	}
	else if (puzz[4] == -1) {
		puzz[4] = puzz[5];
		puzz[5] = -1;
	}
	else if (puzz[6] == 0) {
		puzz[6] = puzz[7];
		puzz[7] = 0;
	}
	else if (puzz[7] == 0) {
		puzz[7] = puzz[8];
		puzz[8] = 0;
	}
	return puzz;
}
int* left(int puzz[9]) {
	
	if (puzz[0] == 0 || puzz[3] == 0 || puzz[6] == 0) {
		return nullptr;
	}
	else if (puzz[1] == 0) {
		puzz[1] = puzz[0];
		puzz[0] = 0;
	}
	else if (puzz[2] == 0) {
		puzz[2] = puzz[1];
		puzz[1] = 0;
	}
	else if (puzz[4] == 0) {
		puzz[4] = puzz[3];
		puzz[3] = 0;
	}
	else if (puzz[5] == 0) {
		puzz[5] = puzz[4];
		puzz[4] = 0;
	}
	else if (puzz[7] == 0) {
		puzz[7] = puzz[6];
		puzz[6] = 0;
	}
	else if (puzz[8] == 0) {
		puzz[8] = puzz[7];
		puzz[7] = 0;
	}
	return puzz;
}

void printPuzz(int puzz[9]) {
	cout << puzz[0] << " " << puzz[1] << " " << puzz[2] << "\n";
	cout << puzz[3] << " " << puzz[4] << " " << puzz[5] << "\n";
	cout << puzz[6] << " " << puzz[7] << " " << puzz[8] << "\n\n\n\n";
}

bool DLS(int src[9], int limit)
{
	if (src == nullptr) {
		return false;
	}
	if (matchGoal(src)) {
		printPuzz(src);
		return true;
	}
		

	// If reached the maximum depth, stop recursing.
	if (limit <= 0)
		return false;
	int temp[9];
	for (int i = 0; i < 9; i++) {
		temp[i] = src[i];
	}
	// Recur for all the vertices adjacent to source vertex
		if (DLS(up(temp), limit - 1) == true) {
			printPuzz(temp);
			return true;
		}
		for (int i = 0; i < 9; i++) {
			temp[i] = src[i];
		}
		if (DLS(down(temp), limit - 1) == true) {
			printPuzz(temp);
			return true;
		}
		for (int i = 0; i < 9; i++) {
			temp[i] = src[i];
		}
		if (DLS(right(temp), limit - 1) == true) {
			printPuzz(temp);
			return true;
		}
		for (int i = 0; i < 9; i++) {
			temp[i] = src[i];
		}
		if (DLS(left(temp), limit - 1) == true) {
			printPuzz(temp);
			return true;
		}

	return false;
}

bool IDDFS(int src[9], int max_depth)
{
	// Repeatedly depth-limit search till the
	// maximum depth.
	for (int i = 1; i <= max_depth; i++) {
		if (DLS(src, i) == true) {
			//printPuzz(src);
			cout << "depth:" << i << "\n";
			return true;
			
		}
	}
			

	return false;
}

int main() {
		
	int puzz[9] = { 2,8,3,1,6,4,7,0,5 };
	//printPuzz(puzz);
	/*int temp[9];
	for (int i = 0; i < 9; i++) {
		temp[i] = puzz[i];
	}
	int* r = right(temp);
	if (r != nullptr) { cout << "r:\n"; printPuzz(r); }
	for (int i = 0; i < 9; i++) {
		temp[i] = puzz[i];
	}
	//int puzzz[9] = { 8,2,3,0,6,4,7,9,5 };
	int* l = left(temp);
	if (l != nullptr) { cout << "l:\n"; printPuzz(l); }
	for (int i = 0; i < 9; i++) {
		temp[i] = puzz[i];
	}
	//int puzzzz[9] = { 8,2,3,0,6,4,7,9,5 };
	int* u = up(temp);
	if (u != nullptr) { cout << "u:\n"; printPuzz(u); }
	for (int i = 0; i < 9; i++) {
		temp[i] = puzz[i];
	}
	//int puzzzzz[9] = { 8,2,3,0,6,4,7,9,5 };
	int* d = down(temp);
	if (d != nullptr) { cout << "d:\n"; printPuzz(d); }
	*/
	
	bool solve = IDDFS(puzz,5);
	if (solve == true) {
		cout << "SOLVED!";
	}
	
	return 0;
}