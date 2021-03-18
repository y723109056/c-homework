#include<iostream>
#include<cmath>

using namespace std;

double mysin(double x);
int main(){
	//1.求一元二次方程的ax^2+bx+c=0的根
	double a, b, c, delt;
	while (true)
	{
		cout << "请输入a,b,c的值" << endl;
		cin >> a >> b >> c;
		if (a!=0) {
			delt = b * b - 4 * a * c;
			(delt > 0) ?
				cout << "方程有两个解,x1=" << (-b + sqrt(delt)) / (2 * a) << ",x2=" << (-b - sqrt(delt)) / (2 * a) << endl
				:
				(delt == 0 ?
					(cout << "方程仅有一个解：" << ((b==0)?0:(-b / 2*a)) << endl)
					:
					(cout<<"方程无解"<<endl));
			
		}
		else {
			b == 0 ?
				(cout << "方程无数解" << endl)
				:
				cout << "方程仅有一个解：" << ((-c / b) == 0 ? 0 : (-c / b)) << endl;
		}
		char end;
		cout <<"是否继续，输入y或者Y,继续,输入其他退出" << endl;
		cin >> end;
		if (end != 'y' && end != 'Y') {
			break;
		}

	}

	//1+2+3+...+100
	int sum = 0;
	for (int i = 1; i <= 100;i++) {
		sum += i;
	}
	cout << "1+2+3+...+100=" << sum << endl;

	//1-1/3+1/5-1/7+....1/99
	double result = 0;
	int flag = 1;
	for (double j = 1; j <= 99;j=j+2) {
		result += (flag * (1 / j));
		flag = (-1) * flag;
	}
	cout << "1-1/3+1/5-1/7+....1/99=" << result << endl;


	//作业1
	char level;
	cout << "请输入分数等级（A/B/C/D/E）" << endl;
	cin >> level;
	switch (level)
	{
	case 'A':
		cout << "分数范围:90-100" << endl;
		break;
	case 'B':
		cout << "分数范围:80-89" << endl;
		break;
	case 'C':
		cout << "分数范围:70-79" << endl;
		break;
	case 'D':
		cout << "分数范围:60-69" << endl;
		break;
	case 'E':
		cout << "分数范围:60以下" << endl;
		break;
	default:
		cout << "对不起,输入的等级不对,请输入A,B,C,D,E..." << endl;
	}

	//作业2
	int core;
	cout << "请输入分数（0~100）" << endl;
	cin >> core;
	switch (core/10)
	{
	case 10:
	case 9:
		cout << "成绩等级：A" << endl;
		break;
	case 8:
		cout << "成绩等级：B" << endl;
		break;
	case 7:
		cout << "成绩等级：C" << endl;
		break;
	case 6:
		cout << "成绩等级：D" << endl;
		break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		cout << "成绩等级：E" << endl;
		break;
	default:
		cout << "输入错误,请输入0~100范围的分数" << endl;
	}

	//求sinx误差
	double x;
	cout << "请输入sinx的参数x:" << endl;
	cin >> x;
	cout << "mysin(" << x << ")=" << mysin(x) << endl;
	cout << "sin(" << x << ")=" << sin(x) << endl;
	cout << "求得绝对值|mysinx(x)-sin(x)|="<<fabs(mysin(x) - sin(x)) << endl;

	system("pause");
	return 0;


}

//要求误差e<10^-9
double mysin(double x) {
	double e = 1e-9;//误差
	double term = x;//项数
	int n=1,sign=1;
	double sum = x;
	while (fabs(term)>=e) {
		sign = -sign;//切换符号
		term =  term * x * x / ((2 * n) * (2 * n + 1));
		sum += sign*term;
		n++;
	}
	return sum;

}