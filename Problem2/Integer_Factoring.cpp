#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

// return true if given num is a prime number, false otherwise
bool isPrime(int num){
  int max_num_tested = (num / 2) + 1; // add one off if odd number to be safe
  for(int i = 2; i < max_num_tested; i++){
    if(num % i == 0){
      return false; // its composite
    }
  }
  return true; // its prime
}
// find factors of that given num and add them into the given vector reference
bool find_factors(unsigned int num, vector<int>& all_factors){
  bool factored = false;
  int i = 2;
  while(!factored){
    if(num % i == 0 && num != 2){ //if num is evenly divisible and not the prime number 2
      all_factors.push_back(i);
      all_factors.push_back(num / i);
      factored = true;
    }
    if(num % 2 == 0 && i > (num / 2)){//if num is even and i is greater than half of num
      break;
    }
    else if(num % 2 != 0 && ((i * 1.0) > (num / 2.0))){//if num is odd and i is greater than half of num
      break;
    }
    i += 1;
  }
  return factored;
}

void prime_factorization(unsigned int num){
  bool no_more_factors = false;
  unsigned int first_num = num;
  vector<int> prime_nums;
  vector<int> all_factors;


    if(find_factors(num, all_factors) == true){// if this is false then the given num is already prime
      // resizes vector when new factors added so the loop continues until all factors found and stopped at prime factors
      for(int i = 0; i < all_factors.size(); i++){
        find_factors(all_factors.at(i), all_factors);
      }
    }
    else {
      cout << "The Prime factorization of " << num << " is: " << endl;
      cout << num << endl;
      return;
    }

  for(int i = 0; i < all_factors.size(); i++){
    if(isPrime(all_factors.at(i))){
      prime_nums.push_back(all_factors.at(i));
    }
  }

  cout << "The Prime factorization of " << num << " is: " << endl;
  for(int i = 0; i < prime_nums.size(); i++){
    if(i == prime_nums.size() - 1){
      cout << prime_nums.at(i);
    }
    else{
      cout << prime_nums.at(i) << " X ";
    }
  }

  cout << endl;
}


int main() {
    unsigned int number = 0;
    cout << "Please enter a positive integer greater than one: " << endl;
    cin >> number;
    prime_factorization(number);
    return 0;
}
