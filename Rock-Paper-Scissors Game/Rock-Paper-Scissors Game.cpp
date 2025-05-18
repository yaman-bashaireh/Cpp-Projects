#include <iostream> 
#include <string>
#include <cstdlib>
using namespace std;

enum enWinner
{
	Player1 = 1,
	Computer = 2,
	Draw = 3
};
enum enGameChoice
{
	Stone = 1,
	Paper = 2,
	Scissors = 3
};
struct stGameResult
{
	short GameRound = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};
struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

short RandomNumber(short from, short to)
{
	short Randomnumber = rand() % (to - from + 1) + from;
	return Randomnumber;
}

short ReadHowManyRounds()
{
	short GameRound = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRound;

	} while (GameRound < 1 || GameRound>10);

	return GameRound;
}

enGameChoice ReadPlayer1Choice()
{
	short choice = 1;
	do
	{
		cout << "Your choice : [1]:Stone, [2]:Paper, [3]:Scissors \n";
		cin >> choice;
	} while (choice < 1 || choice>3);
	return enGameChoice(choice);
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
			return enWinner::Computer;
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
			return enWinner::Computer;
		break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
			return enWinner::Computer;
		break;
	}

	//if you reach here then player 1 is the winner
	return enWinner::Player1;
}

string WinnerName(enWinner winner)
{
	string WinnerName[3] = { "Player1","Computer", "Draw" };
	return WinnerName[winner - 1];
}

string ChoiceName(enGameChoice gameChoice)
{
	string choice[3] = { "stone", "paper", "scissors" };
	return choice[gameChoice - 1];
}

void SetWinnerScreenColor(enWinner winner)
{
	if (winner == enWinner::Player1)
		system("color 2F");
	else if (winner == enWinner::Computer)
		system("color 4F");
	else
		system("color 6F");
}

void PrintRoundResult(stRoundInfo roundInfo)
{
	cout << "------------Round [" << roundInfo.RoundNumber << "] ------------ \n\n";
	cout << "Player1 choice  : " << ChoiceName(roundInfo.Player1Choice) << endl;
	cout << "Copmuter choice : " << ChoiceName(roundInfo.ComputerChoice) << endl;
	cout << "Round Winner    : [" << roundInfo.WinnerName << "] \n";
	//cout << "----------------------------------\n";

	SetWinnerScreenColor(roundInfo.Winner);
}

enWinner WhoWonTheGame(short player1WinTimes, short ComputerWinTimes)
{
	if (player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	if (ComputerWinTimes > player1WinTimes)
		return enWinner::Computer;
	else return enWinner::Draw;
}

stGameResult FillGameResults(short RoundsNumber, short player1WinTimes, short ComputerWinTimes, short drawTimes)
{
	stGameResult GameResult;
	GameResult.GameRound = RoundsNumber;
	GameResult.Player1WinTimes = player1WinTimes;
	GameResult.ComputerWinTimes = ComputerWinTimes;
	GameResult.DrawTimes = drawTimes;
	GameResult.GameWinner = WhoWonTheGame(player1WinTimes, ComputerWinTimes);
	GameResult.WinnerName = WinnerName(GameResult.GameWinner);

	return GameResult;
}

stGameResult PlayGame(short RoundsNumber)
{
	stRoundInfo RoundInfo;
	short player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= RoundsNumber; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begin: \n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResult(RoundInfo);
	}

	return FillGameResults(RoundsNumber, player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	for (short i = 1; i <= NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "-----------------------------------------------------------\n";
	cout << Tabs(2) << "		+++++ G a m e  O v e r ++++ \n";
	cout << Tabs(2) << "-----------------------------------------------------------\n\n\n";
}

void ShowGameResult(stGameResult GameResult)
{
	cout << Tabs(2) << "--------------------- [Game Result] ---------------------\n\n";
	cout << Tabs(2) << "Game Round	   : " << GameResult.GameRound << endl;
	cout << Tabs(2) << "Player1 won times  : " << GameResult.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times : " << GameResult.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw times         : " << GameResult.DrawTimes << endl;
	cout << Tabs(2) << "Final winner       : " << GameResult.WinnerName << endl;
	cout << Tabs(2) << "------------------------------------\n\n";

	SetWinnerScreenColor(GameResult.GameWinner);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'y';
	do
	{
		stGameResult GameResult = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowGameResult(GameResult);
		cout << Tabs(2) << "Do you want to play again ? (Y, N)" << endl;
		cout << Tabs(2);
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}




int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	return 0;
}