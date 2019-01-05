//
//  main.cpp
//  HW0 - Hello World
//
//  Created by Pansy Ng on 9/26/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>
using namespace std;
/* I would like to see teleportation machine in the future. People can travel to different places in
 a second.
 */
int main() {
    bool play = false;
    int power, base, negPower;
    
    while (!play) {
        double answer = 1.0;
        
        cout << "Let's calculate the power of a number! (base number 0 to exit) Base number?" << endl;
        cin >> base;
        
        // enter 0 to exit
        if(base == 0){
            play = true;
            cout << "Thank you for playing! " << endl;
        }
        
        else {
            
            cout << "To the power of? " << endl;
            cin >> power;
        
            if(power > 0){
                //using for loop to multiply the base in power times
                for (int i = 0; i < power; i++){
                    answer *= base;
                }
            }
        
            else if (power < 0){
                // answer = 1 / (base ^ (power * -1)) and negPower is power * -1
                negPower = power * -1;
                
                //using for loop to multiply the base in power times
                for (int i = 0; i < negPower; i++){
                    answer *= base;
                }
                answer = 1 / answer;
            }
         
            cout << base << " ^ " << power << " = " << answer << endl;
        }
         
    }
    return 0;
}
