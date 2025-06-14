#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;
int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int currentRefill = 0,numRefills = 0;
    stops.insert(stops.begin(),0); 
    int n = stops.size()-1;
    
    while(currentRefill<=n){
    int lastRefill = currentRefill;
        while(currentRefill<=n && stops[currentRefill+1] - stops[lastRefill] <= tank){
        currentRefill++; 
        }
        if(lastRefill == currentRefill) return -1;
        if(currentRefill <= n){
            numRefills++;
        }
        if(dist-stops[currentRefill]> tank) return -1;
    } 
    return numRefills;
}


int main() {
    cout<<"Enter the distance to the destination"<<endl;
    int d = 0;
    cin >> d;
    cout<<"Enter Maximum distance your car can travel on full tank"<<endl;
    int m = 0;
    cin >> m;
    int n = 0;
    cout<<"Enter number of steps"<<endl;
    cin >> n;
    cout<<"Enter the distance of these stops from the source"<<endl;
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
