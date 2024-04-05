#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

const int __MAX__ = 20;

void input(int number[], int& number_size);
void output(const int number[], int number_size);
void add(int first[], int first_size, int second[],
         int second_size, int sum[], int& sum_size);

int main()
{
    int first[__MAX__+1], second[__MAX__+1], sum[__MAX__+1];
    int first_size, second_size, sum_size;
    
	cout << "Large integer summing program " << endl;
    
	cout << "Please enter an integer, 20 digits or less " << endl;
    input(first, first_size);
    
	cout << "you entered " << endl;
    output(first, first_size);

    cout << endl;
    cout << "Enter another integer, 20 digits or less" << endl;
    input(second, second_size);

   	cout << "you entered " << endl;
    output(second, second_size);
    cout << endl << endl;

    cout << "The sum is: " << endl;
    output(first, first_size);
    cout << endl;
    output(second, second_size);
    cout << endl;
    cout << "+" << endl;
    cout << "---------------------" << endl;
    add(first, first_size, second, second_size, sum, sum_size);
    output(sum, sum_size);
    cout << endl;
    	
    return 0;
}


void input(int number[], int& number_size){

    bool no_error = true;
    char ch;
    int i=0;
    number_size=0;

    cin.get(ch);
    while(ch != '\n'){   
        if(!isdigit(ch)){
            cout << "non digit entered. Aborting. " << endl;
            exit(0);
        }
        number[i] = int(ch) - int('0');
        number_size++;
        i++;
        cin.get(ch);
    }

    if(number_size > __MAX__){
        cout << "Input number size too large. Aborting." << endl;
        exit(0);
    }

    /* Reversing */ 
    for(int j = 0; j < number_size/2; j++){
        int temp = number[j];
        number[j] = number[number_size - j - 1];
        number[number_size - j - 1] = temp;
    }

}

void output(const int number[], int number_size)
{

    for(int i = __MAX__; i >= number_size; i--)
        cout << " ";
    for(int i = number_size-1; i >= 0; i--)
        cout << number[i];
}


void add(int first[], int first_size, int second[], int second_size, int sum[], int& sum_size){

    int larger_size, carry=0;

    if(first_size > second_size){
        for(int i=second_size; i < first_size; i++)
            second[i]=0;
        larger_size = first_size;
    }
    else{
        for(int j=first_size; j < second_size; j++)
            first[j]=0;
        larger_size = second_size;
    }

    /* adittion */
    for(int k=0; k < larger_size; k++){
        sum[k] = first[k] + second[k] + carry;
        if(sum[k] > 9){
            carry = 1;
            sum[k] -= 10;
        }
        else
            carry = 0;

        if(carry == 1){
            if(larger_size == __MAX__){
                cout << "An overflow has occurred. "
                << "Result is set to 0" << endl;
                sum_size = 1;
                sum[0] = 0;
                break;
            }
            else{
                sum[larger_size] = carry;
                sum_size = larger_size + 1;
            }
        }
        else /* No carry */
            sum_size = larger_size;

    }
}

