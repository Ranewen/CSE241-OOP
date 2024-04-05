#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; 
 
bool controlLengths(const string, const int);
bool controlDigitNum(const string);
bool compareTheNums(string secretNum, string estimation);
bool controlContainSameDigit(string str,int x);
bool isErrorExist(const int _argc,char** _argv);
string generateSecretNum(int x);
string deleteFirstDigitZero(string str);
/*
argv[0]: ./mastermind
argv[1]: -r or -u
argv[2]: digit size like 1 ... 6,7..9
*/
int counter = 0; 					/* counter for iterations */
const int MAX_ITERATION = 100;      /* Iteration limit, once exceeded game will stop, user will be informed that they failed. */

int main(int argc, char** argv) 
{ 
	srand(time(NULL)); /* Set random seed. */
	/* instead of working with argv the veriables are easier */
	int digit_size; 		/* if option is -r fills digit_size; if option is -u fills secret_num */
	string gameOption; 		/* -r or -u */
	string prediction; 		/* prediction of user */
	string secret_num; 		/* secret_num that created by computer or entered by user */
	bool thereIsError = false; /* for controling the while loop */

	thereIsError = isErrorExist(argc,argv); /* if an error exist returns true */
	if(thereIsError)
		return 1;
	gameOption = argv[1];

	if(gameOption == "-r") /* not secret num is entered but length of that is entered */
	{	
		digit_size = argv[2][0]-'0'; //char-to-int
		secret_num = generateSecretNum(digit_size);
	}
	else if(gameOption == "-u") /* secret_num is entered by user! */
	{ 
		secret_num = (string)argv[2];
		digit_size = ((string)argv[2]).length();
		thereIsError = controlContainSameDigit(argv[2],1);

	} 			

	if(thereIsError)
		return 1;
	thereIsError = controlDigitNum(argv[2]); /* for controlling the main's arguments for the first time */
	
	while(!thereIsError) /* while there isn't any error */
	{
		cin>>prediction;
		if(prediction[0]=='0') /* if user entered a number start with 0 */
			prediction = deleteFirstDigitZero(prediction);

		if(controlContainSameDigit(prediction,2))
			break;
		if(controlDigitNum(prediction))/* if an error exist returns true */
			break;
      	if(controlLengths(prediction,digit_size))/* if an error exist returns true */
			break;
      	cin.ignore(10000,'\n'); /* to clear the stdin */
		cin.clear();			/* to clear the stdin */
		counter++;
		thereIsError = compareTheNums(secret_num,prediction);
		/* Continue the game until the set limit. */
		if(counter== MAX_ITERATION)
		{
			cout<<"FAILED"; /* Prints when loop ends by the iteration count. */
			break;
		}
	}

    return 0; 
}

/*
precondition: takes two string one is secret_num other is user estimation
postcondition: return true if the given string nums are equal
compares two num which are string if they are equal return true otherwise returns false and prints the hint
*/
bool compareTheNums(string secretNum, string estimation)
{
	int leftHint=0, rigthHint=0; 
	int temp;
	bool _r = false;
	if(estimation.compare(secretNum) ==0) /* if they are equal */
	{
		cout<<"FOUND"<<" "<<counter; /* Inform the user that they won. */
		_r = true; /* Terminate. */
	}
	else
	{
		for(int i=0; i<secretNum.length(); i++)
		{
			if(secretNum[i]==estimation[i])
				leftHint++;
			else
			{
				temp = estimation[i];
				for(int j=0; j<secretNum.length(); j++) /* this for loop looks all numbers in string for each estimation member */
				{ 
					if(temp==secretNum[j])
						rigthHint++;
				}
			}
		}
		cout<<leftHint<<" "<<rigthHint<<endl;
	}
	return _r;
}
/*
precondition: takes mains arguments (argc and argv)
postcondition: Controls the initial values which are entered with progrom calling.
if there is an unexpected value or missing value or something wrong, returns true
else returns false. And also doesn't change the given values.
*/
bool isErrorExist(const int _argc, char** _argv) /* if there is an error returns true */
{
	bool r_value = false;
	/* we don't want to take extra or less arguments */

	if(_argc!=3) /* If number of given arguments are not exactly 3, print error code 'E0' and proceed to terminate. */
	{ 
		cout<<"E0"; /* Print the error message. */
		return true; /* Terminate. */
	}
	else if((string)_argv[1]=="-u" && _argv[2][0] == '0')
	{
		cout<<"E0"; /* Print the error message. */
		r_value = true; 
	}
	/* digit cannot be a zero or negatif value otherwise terminate! */
	else if((string)_argv[1]=="-r")
	{
		if(!isdigit(_argv[2][0]))
		{
			cout<<"E0"; /* Print the error message. */
			r_value = true; 
		}
		else if(_argv[2][0]-'0'<=0 || ((string)_argv[2]).length()>1) 
		{
			cout<<"E0"; /* Print the error message. */
			r_value = true; 
		}
	}
	
	/* the name of game is mastermind. otherwise terminate! */
	else if((string)_argv[0]!="./mastermind")  
	{
		cout<<"E0"; /* Print the error message. */
		r_value = true; 
	}
	/* there are only 2 option for playing game otherwise terminate! */
	else if((string)_argv[1]!="-r" && (string)_argv[1]!="-u") 
	{
		cout<<"E0"; /* Print the error message. */
		r_value = true; 
	}
	
	return r_value;

}

/*
preconditon: takes a string which is the user input 
postcondition: returns true if it's not a digit num does nothing otherwise
*/
bool controlDigitNum(const string str)
{
	bool _r = false;
	if(str[0]=='-')	/* if the entered number is negative */
	{
		cout<<"E0"; /* Print the error message. */
		return true; /* Terminate. */
	}
	for(int i=0; i<str.length(); i++)
	{
		if(!isdigit(str[i])) /* if it's not a digit */
		{
			cout<<"E2"; /* Print the error message. */
			_r = true; 
			break;
		}
	}
	return _r;
}

/*
preconditon: Takes a string and int (expected length)
postcondition: returns true if the expected length and string length are not equals does nothing otherwise
*/
bool controlLengths(const string str, const int x)
{
	bool _r = false;
	if(str[0]=='0') /* if first digit is 0 there is a problem there */
	{
		if(str.length()-1 != x) /* 0123 is a number which has 3 digit */
		{
			cout<<"E1"; /* Print the error message. */
			_r = true; 
		}

	}
	else if(str.string::length() != x)
	{
		cout<<"E1"; /* Print the error message. */
		_r = true;
	}
	return _r;
}

/* Checks if there are any same numbers. If returns true this means yes */ 
bool controlContainSameDigit(string str, int x)
{
	if(str.length()==0)
		return false;
	for(int i =0; i<str.length(); i++)
	{
		for(int j=i+1; j<str.length(); j++)
		{
			if(str[i]==str[j])
			{
				if(x==1)
					cout<<"E0"; /* Print the error message. */
				else 
					cout<<"E1"; /* Print the error message. */
				return true;
			}
		}
	}
	return false;
}

/*
precondition: takes an int which is length of the requested secret num
postcondition: creates and sends a secret number in string format in each iteration creates only one number and add that up to the string
*/
string generateSecretNum(int x)
{
	string s;
	int rand_Num;
	string temp_String;
	bool isUsedBefore = false;

	rand_Num = rand()%9+1; /* 1....9 the first number should not be 0 */
	temp_String= to_string(rand_Num);
	s+=temp_String;
	if(x==1) /* if length of the expected num is 1 */
		return s;
	while(1)
	{
		rand_Num = rand()%10; /* 0....9. creates only one number in each iteration */
		temp_String = to_string(rand_Num); //change int to a tempstring 
		/* this for loop checks if the just created number is used before */
		for(int i=0; i<s.length(); i++) 
		{
			if(s[i] == temp_String[0]) /* if this number is used before, exit from loop */
			{
				isUsedBefore = true;
				break;
			}
		}
		if(!isUsedBefore) /* else add that up to the string */
			s+=temp_String;
		else 
			isUsedBefore = false;
		
		if(s.length()==x) /* is expected length is reached exit from while */
			break;
	}
	return s;
}

/* Removes first digit if it's zero while playing in -r*/
string deleteFirstDigitZero(string str)
{
	string temp;
	for(int i=1;i<str.length(); i++)
		temp+=str[i];
	if(temp[0]=='0')
		deleteFirstDigitZero(temp);
	return temp;
}
