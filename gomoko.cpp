#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int M = 15;
const int a_row = 5;
const int n_players = 2;
char marks[n_players] = {'X', 'O'};
char grid[N][M];

//This function prints the grid of Gomoku as the game progresses
void print_grid() {
	for (int i = 0; i< n_players; i++) {
        cout << "Player " << i+1 << ": " << marks[i] << "  ";
        if (i < n_players-1)
            cout << "vs  ";
	}
	cout << "\n";
	cout << "--";
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < M; cout << "---", i++);
        cout << "--\n";
    }
}
//This function checks if the game has a win state or not
bool check_win(int i , int j ,char mark) {
    for (int i=0; i<N; i++){
            int count1=0;  int count2=0; int count3=0;
        for (int j=0; j<N; j++){
            if (grid[i][j] == mark){
                count1 += 1;
                    if (count1 == 5){ //row
                        return true;
            }}
                if (grid[j][i] == mark){ //coloumn
                     count3 += 1;
                    if (count3 == 5){
                        return true;
                }}

        }}
            int co1 = 0; //dig right
    int v=j;int k = i;
    while (j<=v && v<N && i<=k && k<M){
        if (grid[k][v] == mark){
            co1 +=1 ;}
        else{
            break;}
        v += 1;
        k += 1;}

    int f=j-1 ; int x = i - 1;
    while (-1<f && f<j && -1<x && x<i){
        if (grid[x][f] == mark){
            co1 += 1;}
        else{
            break;}
        f -= 1;
        x -= 1;}
    if (co1 >= 5){
        return true;}

       int co2 = 0; //dig left
    int a=j ;
    int y=i;
    while (a < N && -1 < y){
        if (grid[y][a] == mark){
            co2 += 1;}
        else{
            break;}
        a += 1;
        y -= 1;}
    int vc=j-1; int vb = i + 1;
    while (-1 < vc && vb < 7){
        if (grid[vb][vc] == mark){
            co2 += 1;}
        else{
            break;}
        vc -= 1;
        vb += 1;}
    if (co2 >= 5){
        return true;}

return false;

}
//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark) {

    for (int i=0; i<N; i++){
            int count1=0; 
        for (int j=0; j<M; j++){
            if (grid[i][j] == mark || grid[i][j] == '.' ){ // row
                count1 += 1;
                    if (count1 == 5){
                        return false;}
            else {break;}
            }}}

    for (int j=0; j<M; j++){
            int count2=0; 
        for (int i=0; i<N; i++){
            if (grid[i][j] == mark || grid[i][j] == '.' ){ //column
                count2 += 1;
                if (count2 == 5){
                    return false;  
                }}
            else {break;}}}
        
    for (int i=0 ; i<(N/2) ; i++){
        for (int j=0 ; j<M ; j++,i++){
            int count3=0; 
            if (grid[i][j] == mark || grid[i][j] == '.' ){ //d right
                count3 += 1;
                if (count3 == 5){
                    return false;  
                }}
            else {break;}}}

    for (int j=0 ; j<(M/2+1) ; j++){
        for (int i=0 ; i<N ; j++,i++){
            int count3=0; 
            if (grid[i][j] == mark || grid[i][j] == '.' ){ //d right
                count3 += 1;
                if (count3 == 5){
                    return false;  
                }}
            else {break;}}}
            
    for (int j=(M/2) ; j<M ; j++){
        for (int i=0 ; i<N ; j--,i++){
            int count3=0; 
            if (grid[i][j] == mark || grid[i][j] == '.' ){ //d left
                count3 += 1;
                if (count3 == 5){
                    return false;  
                }}
            else {break;}}}

    for (int i=0 ; i<(N/2) ; i++){
        for (int j=M-1 ; j>0 ; j--,i++){
            int count3=0; 
            if (grid[i][j] == mark || grid[i][j] == '.' ){ //d left
                count3 += 1;
                if (count3 == 5){
                    return false;  
                }}
            else {break;}}}
    return true;

} 

//This function checks if the  game has a tie state or not
bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
    /*for (int i =0 ; i<N; i++){
        for (int j =0 ; j<M; j++){
            if (grid[i][j] == '.'){
                return false;
            }
    }} return true;*/
   }

//This function checks if given cell is empty or not
bool check_empty(int i, int j) {
    bool empty = grid[i][j]=='.';
   return empty;

}
//This function checks if given position is valid or not
bool check_valid_position(int i, int j) {
    bool valid= 0<=i<=N && 0<=j<=N;
     return valid;

}
//This function sets the given mark to the given column
void set_cell(int i, int j, char mark) {
    grid[i][j] = mark;

}
//This function clears the game structures
void grid_clear() {
     for (int i =0 ; i<N; i++){
            for (int j =0 ; j<M; j++){
                grid[i][j]='.';
            }
        }

}
//This function reads a valid position input
void read_input(int &i, int &j) {
    cout << "Enter the row index and column index: ";
    cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j)) {
        cout << "Enter a valid row index and a valid column index: ";
        cin >> i >> j;
    }
}
//MAIN FUNCTION
void play_game() {
    cout << "Gomoku Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
		read_input(i, j);
        //Set the input position with the mark
        set_cell(i, j, marks[player]);
        //Check if the state of the grid has a win state
        if (check_win(i,j,marks[player])) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the state of the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = (player + 1) % n_players;
    }
}
int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
