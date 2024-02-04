#include <stdexcept>
#include <string>
#include <limits>
#include <iostream>
using std::cout, std::endl;

int Largest(int a, int b, int c) {
  int large = a;

  if (b > a){
    large = b;
  }
  if (c > b){
    large = c;
  }
  
  return large;
}

bool SumIsEven(int a, int b) {
  if((a+b)%2){
    return false;
  }else{
    return true;
  }
}

int BoxesNeeded(int apples) {
  if(apples > 0){
    if (apples%20 == 0){
      return apples/20;
    }
    return 1 + apples/20;
  }
  return 0;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  

  if (A_correct < 0){
    throw std::invalid_argument("no exception");
  }
  if (B_correct < 0){
    throw std::invalid_argument("no exception");
  }
  if (A_total <= 0){
    throw std::invalid_argument("no exception");
  }
  if(B_total <= 0){
    throw std::invalid_argument("no exception");
  }

  if (A_correct > A_total){
    throw std::invalid_argument("no exception");
  }
  if (B_correct > B_total){
    throw std::invalid_argument("no exception");
  }

  float a = (float)A_correct / (float)A_total;
  float b = (float)B_correct / (float)B_total;

  return a > b;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if ((pizzas >= 10) && (pizzas <= 20)) {
    return true;
  }
  else if (is_weekend && (pizzas > 20)) {
    return true;
  }
    return false;
}

int SumBetween(int low, int high) {
  int value = 0; 

  cout << "low: " << low << endl;
  cout << "high: " << high << endl;

  if (low > high){ // low  pos
    throw std::invalid_argument("invalid input");
  }
  if(low == high){
    return low;
  }
  if (abs(low) == abs(high)){
    return 0;
  }
  if (low == INT32_MIN && high == INT32_MAX){
    return INT32_MIN;
  }
  if (low >= 0 && high >= 0){  // both pos
    for (int n = low; n <= high; n++) {
      if (value > INT32_MAX - n){
        throw std::overflow_error("overflow max in sumbetween");
      }
      value += n;
    }
  }
  if (low <=0 && high <=0){ // both neg
    for (int n = low; n <= high; n++) {
      if(value < INT32_MIN - n){ 
        throw std::overflow_error("overflow min in sumbetween");
      }
      value += n;
    }
  }

  if (low < 0 && high > 0){ //low neg high pos
    if( abs(low) - high == 1){
      return low;
    }
    if(abs(low) - high == -1){
      return high;
    }

    if (abs(low) > high){
      for (int n = low; n < -high; n++){
        if(value < INT32_MIN - n){
          throw std::overflow_error("overflow min in sumbetween");
        }
        value += n;
      }
    }
    
    if (high > abs(low)){
      for (int n = abs(low) + 1; n <= high; n++){
        if(value > INT32_MAX - n){
          throw std::overflow_error("overflow max in sumbetween");
        }
        value += n;
      }
    }
  }

  return value;
}

int Product(int a, int b) {

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  if (a == 0 || b == 0) {
    return 0;
  }

  if (a > 0) { // a pos
    if (b > 0){
      if (b > INT32_MAX / a){
        throw std::overflow_error("overflow max inside product");
      }else{
        return a * b;
      }
    }else if (b < 0){
      if (b < INT32_MIN / a){
        throw std::overflow_error("overflow min inside product");
      } else{
        return a * b;
      }
    }
  }

  if(a < 0){
    if(b < 0){
      if (b < INT32_MAX / a){
        throw std::overflow_error("overflow max inside product ");
      }else{
        return a * b;
      }
    }else if (b > 0){
      if(b > INT32_MIN / a){
        throw std::overflow_error("overflow min inside product");
      }else{
        return a * b;
      }
    }
  }
  
  return a * b;
}