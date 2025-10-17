#include <iostream>
#include <string>
using namespace std;

class Card{
        private:
        int its_number;
        char its_suit;

        public:
        Card(int number = 0, char suit = ' '){
                if (1 <= number and number <= 13){
                        its_number = number;
                }
                if (suit == 'C' or suit == 'H' or suit == 'S' or suit == 'D'){
                        its_suit = suit;
                }
        }
        int get_number(){
                return its_number;
        }
        char get_suit(){
                return its_suit;
        }
        string card_name(){
                switch(its_number){
                        case 1:
                                return "Ace";

                        case 13:
                                return "King" ;

                        case 12:
                                return "Queen";

                        case 11:
                                return "Jack";

                        default:
                                return to_string(its_number);
                        }
        }
        string card_suitname(){
                switch(its_suit){
                        case 'S':
                                return "Spades";
                        case 'H':
                                return "Hearts";

                        case 'D':
                                return "Diamonds";

                        case 'C':
                                return "Clubs";
                        default:
                                return "Unknown";

                }
        }
};



int main(){
        int n;
        cin >> n;
        Card* cards = new Card[n];

        for (int i = 0; i < n; i++){
                int card_num;
                char card_suit;
                cin >> card_num >> card_suit;
                cards[i] = Card(card_num, card_suit);
        }


        int sum = 0;
        for (int a = 0; a < n; a++){
                sum += cards[a].get_number();
        }
        bool flush = true;
        for (int b = 1; b < n; b++){
                if (cards[b].get_suit() != cards[0].get_suit()){
                        flush = false;
                        break;
                }
        }
        bool duplicate = false;
        for (int c = 0; c < n; c++){
                for (int d = c + 1; d < n; d++){
                        if (cards[c].get_number() == cards[d].get_number() && cards[c].get_suit() == cards[d].get_suit()){
                                duplicate = true;
                                break;
                        }
                }
                if (duplicate) break;
        }
        cout << "Sum: " << sum << endl;
        if (flush == true){
                cout << "Flush: true " << endl;
        } else {
                cout << "Flush: false " << endl;
        }

        if (duplicate == true){
                cout << "Duplicate: true" << endl;
        } else {
                cout << "Duplicate: false" << endl;
        }

        for (int f = 0; f < n ; f++){
                cout << f + 1 <<". "<< cards[f].card_name() << " of " << cards[f].card_suitname() << endl;
        }
        delete[] cards;

        return 0;
}
