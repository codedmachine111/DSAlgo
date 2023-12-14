#include <iostream>
void alphaTriangle(int n)
{
    // Write your code here.
    int spaces = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            std::cout << "*";
        }
        for (int j = 0; j < spaces; j++)
        {
            std::cout << " ";
        }
        for (int j = 0; j <= n - i - 1; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
        spaces += 2;
    }
    // reverse
    spaces = 2*n -2;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        for (int j = 0; j < spaces; j++)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
        spaces -= 2;
    }
}

void pattern20(int n){
    int spaces = n-1;
    for(int i=1; i<=n; i++){
        if(i<= n/2 +1){
            for(int j=0; j<i; j++){
            std::cout << "*" << " ";
            }
            for(int j=0; j<spaces; j++){
                std::cout << "  ";
            }
            for(int j=0; j<i; j++){
                std::cout << "*" << " ";
            }
            std::cout << "\n";
            if(spaces !=0){
                spaces-=2;
            }
        }else{
            for(int j=0; j<n-i+1; j++){
            std::cout << "*" << " ";
            }
            for(int j=0; j<spaces+2; j++){
                std::cout << "  ";
            }
            for(int j=0; j<n-i+1; j++){
                std::cout << "*" << " ";
            }
            std::cout << "\n";
            spaces+=2;
        }
        
    }

}

void squarepattern(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==n-1 || i==0 || j==0 || j==n-1){
                std::cout << "*";
            }else{
                std::cout << " ";
            }
        }
        std::cout<< "\n";
    }
}
int min(int a, int b){
    return (a<b) ? a :b;
}

void numberpattern(int n){
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int top =i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;

            std::cout << (n- min(min(top,down),min(right,left)));
        }
        std::cout << "\n";
    }
}

int main()
{
    numberpattern(4);
    return 0;
}