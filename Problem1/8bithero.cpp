#include <iostream>
#include <string>
#include <bitset>
using namespace std;


void getHeroInfo(){
  int gender, weapon, superpower;
  unsigned char hero = 0;
  cout << "Gender: (1 for male and 0 for female)\n";
  cin >> gender;
  cout << "\nWeapon:\n";
  cout << "\t1. axe\n";
  cout << "\t2. sword\n";
  cout << "\t3. gun\n";
  cout << "\t4. bow and arrow\n";
  cin >> weapon;
  cout << "\nsuperpower:\n";
  cout << "\t1. flying\n";
  cout << "\t2. super strength\n";
  cout << "\t3. super speed\n";
  cin >> superpower;

  if(gender == 1){
    hero = hero | 1;//change rightmost bit to 1
  }
  if(weapon == 1){
    hero = hero | 2;//change second bit;
  }
  else if(weapon == 2){
    hero = hero | 4; // change 3rd bit
  }
  else if(weapon == 3){
    hero = hero | 8; // change 4th bit
  }
  else if(weapon == 4){
    hero = hero | 16; //change 5th bit
  }

  if(superpower == 1){
    hero = hero | 32; //change 6th bit
  }
  else if(superpower == 2){
    hero = hero | 64; //change 7th bit
  }
  else if(superpower == 3){
    hero = hero | 128; //change 8th bit
  }
  bitset<8> information(hero);
  cout << "Your encoded hero is: " << information << endl;
}

void displayHeroInfo(bitset<8>& sequence){
  if(sequence[0] == 1){// check if rightmost bit is 1
    cout << "Your hero is a male!\n";
  }
  else {
    cout << "Your hero is a female!\n";
  }
  if(sequence[1] == 1){
    cout << "Your hero's weapon is an axe!\n";
  }
  else if(sequence[2] == 1){
    cout << "Your hero's weapon is an sword!\n";
  }
  else if(sequence[3] == 1){
    cout << "Your hero's weapon is an gun!\n";
  }
  else if(sequence[4] == 1){
    cout << "Your hero's weapon is an bow and arrow!\n";
  }
  if(sequence[5] == 1){
    cout << "Your hero's super power is flying!\n";
  }
  else if(sequence[6] == 1){
    cout << "Your hero's super power is super strength!\n";
  }
  else if(sequence[7] == 1){
    cout << "Your hero's super power is super speed!\n";
  }

}



int main(){
  bitset<8> sequence;
  getHeroInfo();
  cout << "\nNow enter in an 8-bit sequence starting with:";
  cin >> sequence;
  displayHeroInfo(sequence);
  bitset<8> grace_hopper(0b00110000);
  cout << "Grace Hopper is now your hero!\n";
  displayHeroInfo(grace_hopper);
  cout << "Grace Hopper encoded bit sequence would be " << grace_hopper << endl;


  return 0;
}
