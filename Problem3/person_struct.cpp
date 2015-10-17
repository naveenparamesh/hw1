#include <iostream>
#include <string>

using namespace std;

 struct Person{
        string name;
        int age;
        string gender;
        void greet(){
            cout << "Hi my name is: " << name << ". I'm " << age << " years old and i'm a " << gender << ".\n";
        }
    } person_a, person_b;
    

void bodySwap(string& name_choice, string& age_choice, string& gender_choice, Person& a, Person& b){
    if(name_choice == "yes"){
        string temp_name = a.name;
        a.name = b.name;
        b.name = temp_name;
    }
    if(age_choice == "yes"){
        int temp_age = a.age;
        a.age = b.age;
        b.age = temp_age;
    }
    if(gender_choice == "yes"){
        string temp_gender = a.gender;
        a.gender = b.gender;
        b.gender = temp_gender;
    }
}

int main(){
    string name_choice = "";
    string age_choice = "";
    string gender_choice = "";
    cout << "For Person A:\n";
    cout << "What is their name?: ";
    cin >> person_a.name;
    cout << "What is their age?: ";
    cin >> person_a.age;
    cout << "Are they male or female?(enter 'male' or 'female'):";
    cin >> person_a.gender;
    
    cout << "For Person B:\n";
    cout << "What is their name?: ";
    cin >> person_b.name;
    cout << "What is their age?: ";
    cin >> person_b.age;
    cout << "Are they male or female?(enter 'male' or 'female'):";
    cin >> person_b.gender;
    cout << "Do you want person a and b to switch names(yes or no):\n";
    cin >> name_choice;
    cout << "Do you want person a and b to switch ages(yes or no):\n";
    cin >> age_choice;
    cout << "Do you want person a and b to switch genders(yes or no):\n";
    cin >> gender_choice;
    
    person_a.greet();
    person_b.greet();
    cout << "performing body swap..." << endl;
    bodySwap(name_choice, age_choice, gender_choice, person_a, person_b);
    person_a.greet();
    person_b.greet();
    
    
    
    
    
    
    
    return 0;
}