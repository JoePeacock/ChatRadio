#include <iostream>
#include <string>
#include <radio.h>

using namespace std;

int main() {
    
    // Lets go ahead and define some command we want to use.
    string help_command = "help";
    string set_freq_command = "set";
    string exit_command = "exit";

    // Set default broadcast & listen frequency.
    int frequency = 900;     
    string input = "";

    cout << "Welcome to ChatRadio!" << endl;
    cout << "Built by: Joe Peacock & Mike Ferris" << endl << endl;
    
    // init our Radio object
    radio = Radio(active_frequency);
  
    // Start the cli
    while(true)
    {
      cout << active_frequency << "Mhz #> ";
      getline(cin, input);

      if (input.compare(help_command) == 0) 
      {
        cout << "ChatRadio is a two way chatting system using packets to a HopeRF radio." << endl;
        cout << "This is all powered by a Raspberry Pi and C++" << endl << endl;
        cout << "Commands:" << endl;
        cout << "help  :displays a description and list of commands" << endl;
        cout << "set   :sets the frequency for the radio to listen on. (700 to 900Mhz)." << endl;
      }

      if (input.compare(set_freq_command) == 0)
      {
        cout << "Set Frequency #> ";
        getline(cin, input); 
        frequency = stoi(input, nullptr, 0);
        cout << "Succesfully set radio frequency to: " << input << endl;
      }

      if (input.compare(exit_command) == 0)
      {
        cout << "Exiting.." << endl;
        return 0;
      }

    }
    return 0;
}
