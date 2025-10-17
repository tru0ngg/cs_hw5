#include <iostream>
using namespace std;

class Point2i {
        private:
        int x;
        int y;

        public:
        Point2i(int x_val, int y_val){
                x = x_val;
                y = y_val;
        }

        void translate(const Point2i &p){
                x += p.x;
                y += p.y;
        }
        void reflect_x(int p){
                x = 2 * p - x;
        }
        void reflect_y(int p){
                y = 2 * p - y;
        }

        void print(){
                cout << x << " " << y << endl;
        }
};

int main(){
        int x, y;
        cin >> x >> y;
        Point2i point(x,y);

        int N;
        cin >> N;
        for (int i = 0; i < N; i++){
                string command;
                cin >> command;

                if (command == "translate"){
                        int p, q;
                        cin >> p >> q;
                        Point2i move(p, q);
                        point.translate(move);
                }
                else if (command == "reflect_x"){
                        int p;
                        cin >> p;
                        point.reflect_x(p);
                }else if (command == "reflect_y"){
                        int p;
                        cin >> p;
                        point.reflect_y(p);
                }
        }
        point.print();
        return 0;
}
