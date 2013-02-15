#include "Project.h"
#include<iostream>
#include<Math.h>
#include<cstring>

using namespace std;
Project::Project()
{
    //ctor
}

Project::~Project()
{
    //dtor
}

void Project:: multiples_of_3_and_5(){

  int i=0;
  int temp=0;

  for (i=0;i<1000;i++){


    if (i%3==0|| i%5==0){
        temp=i+temp ;

    }


  }

  cout<<  "--------------------------------------------------"<<endl;
  cout<< " Sum of multiples of 3 and 5 from 1-1000: "<<temp<<endl;
  cout<<  "--------------------------------------------------"<<endl;


}

void Project::even_fibonacce(){

 int n, c, first = 0, second = 1, next,sum_even=0;


   for ( c = 0 ; c < n ; c++ )
   {

      if ( c <= 1 ){
         next = c;
      }

      else{
         next = first + second;
         first = second;
         second = next;
      }

      if (next%2==0){
        sum_even=sum_even+next;
      }


      if (next>=4000000){
        break;
      }


   }
   cout<< "----------------------------------------------------------"<<endl;
   cout<< " Sum of even numbers in the fibonacci sequence is:"<<sum_even<<endl;
   cout<< "----------------------------------------------------------"<<endl;


}

void Project:: largest_prime_factor(){

    long long int number = 600851475143;
    long long int halfNumber = number/2; //as 600851475143 isnt a prime number this will work
    long long int sum = 1;

    for(long long int digit = 3; digit <= halfNumber; digit += 2){

        if(number%digit == 0){
            sum*=digit;

            if(sum == number){
            cout << digit << " = " << sum << endl;
            break;
            }

          cout << digit << " x ";

        }
    }

   cout<< "----------------------------------------------------------"<<endl;
   cout << "So the highest prime Factor is 6587"<<endl;
   cout<< "----------------------------------------------------------"<<endl;

}




void Project::largest_palindrome_product() {

    int ans = 0;
    for(int a = 999; a > 1; --a)
        for(int b = a; b > 1; --b){
            int x = a * b;
            int y=x;
            int reverse_x=0;

            while (y){
                    reverse_x=reverse_x*10 +(y%10);
                    y/=10;
            }

	            if(x == reverse_x && x > ans) ans = x;
        }

        cout<< "-----------------------------------------------------------------"<<endl;
        cout << "The largest palndrome product is::"<< ans<<endl;
        cout<< "-----------------------------------------------------------------"<<endl;


}

void Project::smallest_multiple(){
    int num = 0, divisor;

    cout<< "Please wait. This might take a few seconds....." <<endl;

    do
    {
        num++;
        for(divisor = 1; divisor <=20; divisor++)
        {
                if (!(num%divisor == 0))break;
        }
    } while(divisor<=20);

   cout<< "-----------------------------------------------------------------"<<endl;
   cout << "The smallest number divisible by numbers from 1-20 is:"<< num <<endl;
   cout<< "-----------------------------------------------------------------"<<endl;


}

 void Project::sum_square_diff(){
        const unsigned int limit = 100;
	    int i;
	    unsigned long long sumOfSquares = 0;
	    unsigned long long squareOfSums = 0;
	    long long diff;

	    for(i=1;i<=limit;i++){
            sumOfSquares += pow((i),2);
            squareOfSums += i;
	    }

	    squareOfSums = pow(squareOfSums, 2);
	    diff = squareOfSums - sumOfSquares;

	    cout<<"Square of sum: " << squareOfSums<<endl;
	    cout<<"Sum of Squares:" << sumOfSquares<<endl;


        cout<< "-----------------------------------------------------------------"<<endl;
        cout << "The difference is:"<< diff <<endl;
        cout<< "-----------------------------------------------------------------"<<endl;


}


 void Project:: prime_10001st(){
        int MAX=1000000;
        bool p[MAX];

	    memset(p, 1, sizeof(p));
	    int ans = 1000, c = 1;
	    for(int i = 4; i < MAX; i += 2) p[i] = 0;
	    for(int i = 3; i < 1001; i += 2)
	        if(p[i]){
	            ++c;
	            for(int j = i * i; j < MAX; j += i) p[j] = 0;
	        }
	        while(c < 10001) c += p[++ans];

        cout<< "-----------------------------------------------------------------"<<endl;
        cout << "The 10001st prime is: "<< ans<<endl;
        cout<< "-----------------------------------------------------------------"<<endl;
}

 void Project::largest_product_in_series(){
     string str = "73167176531330624919225119674426574742355349194934"
                  "96983520312774506326239578318016984801869478851843"
                  "85861560789112949495459501737958331952853208805511"
                  "12540698747158523863050715693290963295227443043557"
                  "66896648950445244523161731856403098711121722383113"
                  "62229893423380308135336276614282806444486645238749"
                  "30358907296290491560440772390713810515859307960866"
                  "70172427121883998797908792274921901699720888093776"
                  "65727333001053367881220235421809751254540594752243"
                  "52584907711670556013604839586446706324415722155397"
                  "53697817977846174064955149290862569321978468622482"
                  "83972241375657056057490261407972968652414535100474"
                  "82166370484403199890008895243450658541227588666881"
                  "16427171479924442928230863465674813919123162824586"
                  "17866458359124566529476545682848912883142607690042"
                  "24219022671055626321111109370544217506941658960408"
                  "07198403850962455444362981230987879927244284909188"
                  "84580156166097919133875499200524063689912560717606"
                  "05886116467109405077541002256983155200055935729725"
                  "71636269561882670428252483600823257530420752963450";


    int store = 0; // what I need to compare total to later
    int total = 1; // what will be multiplied by inputs from str[]
    int n = 0; // keeps track of single iterations

    for(int i = 0;n<=999;n++) // i = 0 because that's the starting point for place of first number in string (str[0]); because the length is 1 shorter, 999 is the limit
    {
        total = 1; // must be set back to one each successful product loop
        int incr = n + 4; // places for the next 5 after 0

        // A general note: pattern this generates is that the end digit of an even break in groupings will always either be 4 or 9
        // e.g. breaking the loop at position 44, 199, 234 will multiply 5 places properly without error

        if(n == 0) // string starts at 0, must be accounted for especially
        {
            for(;i<=4;i++) // i = str[0] which is then incrmemented to str[4] which is fifth number
            {
                total*=(str[i] - '0'); // takes str[1],str[2],...str[4] and multiplies them together using total as valueholder.

            };

            store = total > store ? total:store; // if total is greater than store, then store = total; simple enough
        };

        for(;i<=incr;i++) // i must be added by 4 now because 0,1,2,3,4 are first five and 1,2,3,4,5 are next
        {

            total*=(str[i] - '0'); // takes str[1],str[2],...str[4] and multiplies them together using total as valueholder.

        };

        store = total > store ? total:store; // if total is greater than store, then store = total; simple enough
        i = (n + 1); // i needs to start at a consecutive n each successful loop
    };


    cout<< "-----------------------------------------------------------------"<<endl;
    cout << "The largest product in a series is :"<< store <<endl;
    cout<< "-----------------------------------------------------------------"<<endl;
}

 void Project::special_pytho_triplet(){

    int limit = 1000;
	    int a = 0;
	    int b = 1;
	    int c = 999;
	    int tmpC = 999;
	    int sum=0;
	    bool notFound = true;
	    int answer = 0;
	    while(notFound){
	      c = --tmpC;
	      b = 1;
	      while(b < c){
                a = limit - (c + b);
                if((pow(a, 2) + pow(b, 2)) == pow(c, 2)){
                    notFound = false;
                    answer = a * b * c;
                    sum=a+b+c;
                    cout<<a<<" + "<<b <<" + " <<c << " = " << sum<<endl;
                    cout<<a<<" x "<<b <<" x " <<c << " = " << answer<<endl;

	          break;
                }
	        c--;
	        b++;
          }
       }
	    cout<< "-----------------------------------------------------------------"<<endl;
        cout << "The product of the Phytagorean triplet is :"<< answer <<endl;
        cout<< "-----------------------------------------------------------------"<<endl;}

 void Project::summation_of_primes(){
    int num=1;
	unsigned long long int total=2;
	int divisor;

	bool prime = true ;

	while (num<2000000)
	{
            prime=true;
                if (num<=1)
                    prime=false;
                else if(num==2||num==3)
                    prime=true;
                else if (num%2==0)
                    prime = false ;
                else
            {

                for(divisor=3; divisor <(pow(2000000,0.5));divisor=divisor+2)
                {
                    if (num==divisor)
                        prime=true;
                    else if (num%divisor==0){
                    prime=false;
                    break;
                    }

                }

            }
            if (prime==true){
                total=total+num;
            }
        num=num+2;

	}
        cout<< "-----------------------------------------------------------------"<<endl;
        cout << "The sum of all primes below 2 million is :"<< total <<endl;
        cout<< "-----------------------------------------------------------------"<<endl;

}





