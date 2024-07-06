#include <bits/stdc++.h>

using namespace std;

double x_equacao(pair<double, double> cord1, pair<double, double> cord2, int y){
    auto x1= cord1.first, y1 = cord1.second;
    auto x2 = cord2.first, y2 = cord2.second;

    double m = (y2 - y1)/(x2 - x1);
    double b = y1-(x1*m);

    return ((y-b)/m);

    
}

bool luan_embaixo(pair<int, int> cord_luan, pair<int, int> cord1, pair<int, int> cord2){
    auto x1= cord1.first, y1 = cord1.second;
    auto x2 = cord2.first, y2 = cord2.second;

    double m = (y2 - y1)/(x2 - x1);
    double b = y1-(x1*m);

    double alt = m*cord_luan.first + b;
    if(cord_luan.second < alt){
        return true;
    }else{
        return false;
    }
}

double intercessao_x(pair<double, double> cord1, pair<double, double> cord2){

    auto x1= cord1.first, y1 = cord1.second;
    auto x2 = cord2.first, y2 = cord2.second;

    double m = (y2 - y1)/(x2 - x1);
    double b = y1-(x1*m);

    return (-b/m);

}

double intercessao_y(pair<double, double> cord1, pair<double, double> cord2){

    auto x1= cord1.first, y1 = cord1.second;
    auto x2 = cord2.first, y2 = cord2.second;

    double m = (y2 - y1)/(x2 - x1);
    double b = y1/(x1*m);

    return b;

}

int main(){

    int x, y, xa, ya, xb, yb;
    cin >> x >> y;
    cin >> xa >> ya;
    cin >> xb >> yb;

    double area_total = x*y;

    bool ret = false;

    pair<int, int> luan_cord = {xa, ya}, lari_cord = {xb, yb};

    double alt_1, alt_2;
    double area_1;
    double m;

    if(ya-yb == 0){

        ret = true;

        if(xb > xa){

            m = (xb-xa)/2.;
            m += xa;

            area_1 = y*m;


        }else{


            m = (xa-xb)/2.;
            m += xb;

            area_1 = y*m;
        }

        



        
        
    }else{

        alt_1 = (pow(xa, 2)-(2*xa*0)-pow(xb, 2)+(2*xb*0)+pow(ya, 2)-pow(yb, 2))/(2*(ya-yb));
        alt_2 = (pow(xa, 2)-(2*xa*x)-pow(xb, 2)+(2*xb*x)+pow(ya, 2)-pow(yb, 2))/(2*(ya-yb));

    

    bool crescente = true;
    if(((alt_2-alt_1)/(x) < 0)){

        crescente = false;
        
    }

    

    if(!crescente){

        if(alt_1 > y && alt_2 < 0){

            double base_menor, base_maior;
            base_menor = x_equacao({0, alt_1}, {x, alt_2}, y);
            base_maior = intercessao_x({0, alt_1}, {x, alt_2}); 
             area_1 = ((base_maior+base_menor)*y)/2.;

            // cout << 1 << endl;

        }else if(alt_1 > y && alt_2 >= 0){

            double base = x_equacao({0, alt_1}, {x, alt_2}, y);

             area_1 = (y*base)+((alt_2+y)*(x-base)/2.);

          //   cout << 2 << endl;


        }else if(alt_1 <= y && alt_2 < 0){

            double base = intercessao_x({0, alt_1}, {x, alt_2});

             area_1 = (alt_1*base)/2.;

           //  cout << 3 << endl;


        }else{


             area_1 = ((alt_1+alt_2)*x)/2.;
                        //  cout << 4 << endl;

        }

    }else{

        if(alt_1 < 0 && alt_2 > y){

            double base_menor, base_maior;
            base_menor = x_equacao({0, alt_1}, {x, alt_2}, y);
            base_maior = intercessao_x({0, alt_1}, {x, alt_2}); 
             area_1 = ((base_maior+base_menor)*y)/2.;

            // cout << 5 << endl;

        }else if(alt_1 < 0 && alt_2 <= y){

             double base = intercessao_x({0, alt_1}, {x, alt_2});

             area_1 = (alt_2*(x-base))/2.;

            // cout << 6 << endl;


        }else if(alt_1 >= 0 && alt_2 > y){

            double base = x_equacao({0, alt_1}, {x, alt_2}, y);

             area_1 = (alt_1*x)+((x+(x-base))*(y-alt_1)/2.);

           //  cout << 7 << endl;

        }else{


             area_1 = ((alt_1+alt_2)*x)/2.;

           //  cout << 8 << endl;

        }

    }

}
    double area_2 = area_total-area_1;

   // cout << alt_1 << " e " << alt_2 << endl;

    //cout << area_1 << " e " << area_2 << endl;

    double prob_luan, prob_lari;

    prob_luan = (area_1*100)/area_total/100.;
    prob_lari = 1 - prob_luan;

    cout << fixed << setprecision(6);

    if(ret){

        if(luan_cord.first < m){
            cout << prob_luan << " " << prob_lari << endl;
        }else{
            swap(prob_luan, prob_lari);
        cout << prob_luan << " " << prob_lari << endl;
        }

    }else{

    if(luan_embaixo(luan_cord, {0, alt_1}, {x, alt_2})){

        cout << prob_luan << " " << prob_lari << endl;
        
    }else{

        swap(prob_luan, prob_lari);
        cout << prob_luan << " " << prob_lari << endl;

    }

    }


    return 0;
}