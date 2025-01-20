#include<iostream>
#include<cmath>

using namespace std;

void wel_print()
{
    cout<<"================================="<<endl;
    cout<<"|       DIGITAL CALCULATOR       |"<<endl;
    cout<<"================================="<<endl;
    cout<<"|    +     |     -     |    /    |"<<endl;
    cout<<"|   ADD    |    SUB    |   DIV   |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|    *     |     %     |    ^    |"<<endl;
    cout<<"|   MUL    |    MOD    |  POWER  |"<<endl;
    cout<<"----------------------------------"<<endl; 
    cout<<"|    L     |     R     |    C    |"<<endl;
    cout<<"|   LOG    |  SQ ROOT  |   CUBE  |"<<endl;
    cout<<"----------------------------------"<<endl;   
    cout<<"|    s     |     c     |    t    |"<<endl;
    cout<<"|   SIN    |    COS    |   TAN   |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|    e     |     m     |    p    |"<<endl;
    cout<<"|   Euler  |   MINUS   |   PI    |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|    q     |     !     |    A    |"<<endl;
    cout<<"|   QUIT   | FACTORIAL |  CLEAR  |"<<endl;
    cout<<"----------------------------------"<<endl;
}

void print(double ans)
{
    cout<<"================================="<<endl;
    cout<<"|      RESULT    | "<< ans <<"		|"<<endl;
    cout<<"================================="<<endl;
    cout<<"|    +     |     -     |    /    |"<<endl;
    cout<<"|   ADD    |    SUB    |   DIV   |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|    *     |     %     |    ^    |"<<endl;
    cout<<"|   MUL    |    MOD    |  POWER  |"<<endl;
    cout<<"----------------------------------"<<endl; 
    cout<<"|    L     |     R     |    C    |"<<endl;
    cout<<"|   LOG    |  SQ ROOT  |   CUBE  |"<<endl;
    cout<<"----------------------------------"<<endl;   
    cout<<"|    s     |     c     |    t    |"<<endl;
    cout<<"|   SIN    |    COS    |   TAN   |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|    e     |     m     |    p    |"<<endl;
    cout<<"|   Euler  |   SIGN    |   PI    |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|    q     |     !     |    A    |"<<endl;
    cout<<"|   QUIT   | FACTORIAL |  CLEAR  |"<<endl;
    cout<<"----------------------------------"<<endl;
}

int main()
{
    long double e, n1 = 0.0, n2 = 0.0;
    long double ans = 0.0;
    char ch;
    wel_print();
    
    do
    {
        cout<<"Enter an operator: ";
        cin>>ch;

        if (ch == 'q' || ch == 'Q')
        {
            cout << " Thanks for using this Digital Calculator!" << endl;
            break;
        }

        if (ch == '!' || ch == 'L' || ch == 'R' || ch == 't' || ch == 's' || ch == 'c' || ch == 'C' || ch == 'm')
        {
            cout<<"Enter the number: ";
            cin>>n1;
        } 
        else if (ch == 'e' || ch == 'E')
        {
            e = 2.718281828459045235;
            cout<<"Enter the number: ";
            cin>>n1;
            ans = n1 * e;
            print(ans);
            continue;
        }
        else if(ch=='A')
        {
        	ans = 0;
        	print(ans);
        	continue;
		}
        else if(ch=='p'||ch=='P')
        {
            cout<<"Enter the number: ";
            cin>>n1;
            if(n1>0)
            {
                ans= n1*3.141592653589793238;
            }
            else
            {
                ans = 3.141592653589793238;
            }
            print(ans);
            continue;
        }
        else
        {
            cout<<"Enter the first number: ";
            cin>>n1;
            cout<<"Enter the second number: ";
            cin>>n2;
        }

        switch(ch)
        {
            case '+':
                ans = n1 + n2;
                break;
            case '-':
                ans = n1 - n2;
                break;
            case '*':
                ans = n1 * n2;
                break;
            case '/':
                if (n2 != 0)
                {
                    ans = n1 / n2;
                }
                else
                {
                    cout << "Error! Division by zero is not allowed." << endl;
                }
                break;    
            case '%':
                if (n2 != 0)
                {
                    ans = (int)n1 % (int)n2;
                }
                else
                {
                    cout << "Error! Division by zero is not allowed." << endl;
                }
                break;
            case '^':
                ans = pow(n1, n2);
                break;
            case '!':
                ans = 1;
                for (int i = 1; i <= n1; i++)
                {
                    ans *= i;
                }
                break;
            case 'L':
                ans = log10(n1);
                break;
            case 'R':
                ans = sqrt(n1);
                break;
            case 'c':
                ans = cos(n1);
                break;
            case 's':
                ans = sin(n1);
                break;
            case 't':
                ans = tan(n1);
                break;
            case 'C':
                ans = n1 * n1 * n1;
                break;
            case 'm':
               	ans= (-1)*n1;
                break;
            default:
                cout << "Invalid operator! Try again." << endl;
                continue;
        }
        print(ans);
        
    } while (true);
    
    return 0;
}
