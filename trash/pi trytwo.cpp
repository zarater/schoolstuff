#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  unsigned int decP;
  unsigned int denom=3;
  float ourPi=4.0f;
  bool addFlop=true;

  cout << "How many loop iterations? " << endl;
  cin >> decP;
  for (unsigned int i=1;i<=decP;i++) {
    if (addFlop) {
      ourPi-=(4.0/denom);
      addFlop=false;
      denom+=2;
    } else {
      ourPi+=(4.0/denom);
      addFlop=true;
      denom+=2;
    }
  }
  cout << setiosflags(ios::showpoint) << setiosflags(ios::fixed) << setprecision(9);
  cout << "Pi calculated with " << decP << " iterations is: ";
  cout << ourPi << endl;
}
