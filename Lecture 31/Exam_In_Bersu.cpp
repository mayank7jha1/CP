#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int a[N] = {0};
int Students_Time[101] = {0};
int n, m;

//We Have to check ki current element tak time m ko exceed ko kar raha hai ki nahi.

//10^5*100==10^7

int Solve() {
	int Total = 0;

	for (int i = 0; i < n; i++) {

		int Extra_Time = Total + a[i] - m;
		int Students_Removed = 0;

		if (Extra_Time > 0) {//x is my extra time for which i have to remove students.

			//Current student ko pass karne ke liye aapko
			//kisi na kisi student ko fail karna padea.

			/*
				Idea: We want to remove the maximum time
				consuming students but not one by one.
			*/

			for (int j = 100; j > 0; j--) {
				if (Students_Time[j] > 0) {

					//This means now you are current standing
					// at the maximum time (j) consuming student
					//and its frequency is Student_Time[j].

					//This is the contribution of the maximum time consuming student.

					int Current_Max_Element_Contribution = j * Students_Time[j];

					if (Extra_Time <= Current_Max_Element_Contribution) {

						//This current max element ki kuch ya saari frequency use
						//karni padegi aur koi aur element nahi chahiye.

						Students_Removed += ((Extra_Time + (j - 1)) / j);

						/*
							Extra Time is : 120
							Current Maximum Element is : 40 and Its frequency is 3.

							120+(40-1)/40==3

							Extra Time is : 119

							119/40=2 (x).

							119+(40-1)=158/40==3

						*/

						break;
					}

					Students_Removed += Students_Time[j];
					Extra_Time -= Current_Max_Element_Contribution;

				}

			}


		}


		//If x<=0 that means the current student will pass on its
		//own.


		Students_Time[a[i]]++;
		Total += a[i];

		cout << Students_Removed << " ";

	}
}




int32_t main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Solve();
}





// 40 80 80 80 40




// 40---->2
// 80---->3