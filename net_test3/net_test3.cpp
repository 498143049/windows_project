#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <deque>
#include <iterator>
using namespace std;
int main() {
    freopen("../../net_test3/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    int num;
    cin >> num;
    vector<int> array(num);
    for (int i = 0; i < num; ++i) {
        cin >> array[i];
    }
    sort(array.begin(),array.end());
    if(num==1) {
        cout<<0<<endl;
        return 0 ;
    }
    int leftvalue= array[num-1],rightvalue = array[num-1];
    int left =0; int right = num-2;
    int sum = 0; int status = 0;
    deque<int> dq;
    dq.push_back(rightvalue);
    static int i = 0;
    while (right>=left){
        int value ;
        if(status==0||status==1){
            value = array[left++];
            status++;
        }
        else{
            value = array[right--];
            status++;
            if(status==4){
                status = 0;
            }
        }
        int num1 = abs(leftvalue-value);
        int num2 = abs(rightvalue-value);

        if(num1>num2){
            sum+=num1;
            leftvalue=value;
            dq.push_front(value);

        }
        else{
            sum+=num2;
            rightvalue=value;
            dq.push_back(value);
        }
        copy(dq.begin(),dq.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }

    cout<<sum<<endl;


}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <deque>
//#include <iterator>
//int main() {
//    using namespace std;
//    int n;
//    freopen("../../net_test3/data/a.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
//    while (cin >> n) {
//        vector<int> height(n);
//        for (int i = 0; i < n; i++) {
//            cin >> height[i];
//        }
//        sort(height.begin(), height.end());
//        deque<int> list;
//        list.push_back(height[n - 1]);
//        int l = 0;
//        int r = n - 2;
//        int cnt = 0;
//        for (int i = 0; i < n - 1; i += 2) {
//            if (!(cnt % 2)) {
//                if (l <= r) {
//                    list.push_front(height[l++]);
//                }
//                if (l <= r) {
//                    list.push_back(height[l++]);
//                }
//            }
//            else if (cnt % 2) {
//                if (r >= l) {
//                    list.push_front(height[r--]);
//                }
//                if (r >= l) {
//                    list.push_back(height[r--]);
//                }
//            }
//            cnt++;
//        }
//        copy(list.begin(),list.end(),ostream_iterator<int>(cout," "));
////        long long ans = 0;
////        for (int i = 1; i < list.size(); i++) {
////            ans += abs(list[i] - list[i - 1]);
////        }
////        if (abs(list[n - 1] - list[n - 2]) < abs(list[n - 1] - list[0])) {
////            ans += abs(list[n - 1] - list[0]) - abs(list[n - 1] - list[n - 2]);
////        }//这个判断，不看用例，根本想不出来，。。。。
////        cout << ans << endl;
//    }
//    return 0;
//}
