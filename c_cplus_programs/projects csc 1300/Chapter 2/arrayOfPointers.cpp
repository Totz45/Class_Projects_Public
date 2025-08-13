#include <iostream>
using namespace std;


int main()
{
	string ** cdArray;
	int* numSongs;
	int numCDs;
	
	cout << "\n\nHow many CDs do you have?\n";
	cin >> numCDs;
	
	cdArray = new string*[numCDs];
	numSongs = new int[numCDs];
	
	for(int i=0; i < numCDs; i++)
	{
		cout << "\nFor CD " << i+1 << " how many songs are on it?\n";
		cin >> numSongs[i];
		cin.ignore();
		
		cdArray[i] = new string[numSongs[i]];
		for(int x = 0; x < numSongs[i]; x++)
		{
			cout << "\nSong Title " << x+1 << ": ";
			getline(cin, cdArray[i][x]);
		}
	}
	
	for(int r=0; r< numCDs; r++)
	{	
		for(int c=0; c<numSongs[r]; c++)
		{
			cout << "\nCD " << r+1 << ", Song " << c+1 << ": ";
			cout << cdArray[r][c];
		}
	}
	
	for(int r=0; r< numCDs; r++)
	{
		delete [] cdArray[r];
	}
	delete [] cdArray;
	delete [] numSongs;
	
	return 0;
}
