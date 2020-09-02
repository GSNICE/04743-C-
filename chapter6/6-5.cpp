#include <iostream>
#include <cmath>
using namespace std;

class CShape
{
protected:
    double acreage; //图形的面积，子类可以访问。
public:
    CShape()
    {
        //cout << "基类的构造函数" << endl;
    }
    virtual~CShape()
    {
        cout << "基类的析构函数" << endl;
    }
    virtual double CalAcr() //计算面积，虚函数
    {
        return 0;
    }
    virtual void SetAcreage(double acre){}; //设置面积值，虚函数
    virtual void PrintInfo(){}; //显示信息，虚函数
    
};

class CRectangle:public CShape
{
    double width,high;   
public:
    CRectangle(double w, double h)
    {//cout << "矩形带参构造函数" << endl;
        width = w;
        high = h;
    }
    CRectangle()
    {// cout << "矩形无参构造函数" << endl;
        width = 0;
        high = 0;
    }
    ~CRectangle()
    {//cout << "矩形的析构函数" << endl;
    }
    virtual double CalAcr();
    virtual void PrintInfo();
    virtual void SetAcreage(double);
};

class CCircle:public CShape
{
    double radius; //半径，私有的
public:
    CCircle(double r)
    {//cout << "圆形带参构造函数"<< endl;
        radius = r;
    }
    CCircle()
    {//cout << "圆形无参构造函数"<< endl;
        radius = 0;
    }
    ~CCircle()
    {//cout << "圆形析构函数"<< endl;
    }
    virtual double CalAcr();
    virtual void PrintInfo();
    virtual void SetAcreage(double);
};

class CTriangle:public CShape
{
    double a, b, c; //三条边的长度，私有的
public:
    CTriangle(double a, double b, double c)
    {//cout << "三角形带参构造函数"<< endl;
        this->a = a;
        this->b = b;
        this->c = c;
    }
    CTriangle()
    {//cout << "三角形无参构造函数" << endl;
        a = 0;
        b = 0;
        c = 0;
    }
    ~CTriangle()
    {//cout << "三角形析构函数" << endl;
    }
    virtual double CalAcr();
    virtual void PrintInfo(); //继承的函数,虚函数
    virtual void SetAcreage(double);

};

double CRectangle::CalAcr() //计算矩形的面积
{
    return width * high;
}

void CRectangle::PrintInfo() //输出矩形的信息
{
    cout << "矩形。\t宽度 =" << this->width << ",高度 =" << this->high << ",面积 =" << this->acreage << endl;
}

void CRectangle::SetAcreage(double acre) //设置面积值
{
    acreage = acre;
}

double CCircle::CalAcr() //计算圆形的面积
{
    return 3.14*radius*radius;
}

void CCircle::PrintInfo() //输出圆形的信息
{
    cout << "圆。\t 半径 =" << this->radius << ",面积 =" << this->acreage << endl;
}

void CCircle::SetAcreage(double acre)
{
    acreage = acre;
}

double CTriangle::CalAcr() //根据海伦公式计算三角形面积
{
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void CTriangle::PrintInfo()
{
    cout << "三角形。三条边分别是:" << this->a << "," << this->b << "," << this->c << ",面积 =" << this->acreage << endl;
}

void CTriangle::SetAcreage(double acre)
{
    acreage = acre;
}

CShape *pShapes[100]; //用来存储各种几何形状，最多100个

int main()
{
    int i, n;
    double temp1, temp2, temp3;
    CRectangle *pr;CCircle *pc; CTriangle *pt;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        switch(c)
        {
        case 'R':case 'r'://矩形
            cin >> temp1 >> temp2;
            pr = new CRectangle(temp1, temp2);
            pr->SetAcreage(pr->CalAcr());
            pShapes[i] = pr;
            break;
        case 'c':case 'C':
            cin >> temp1;
            pc = new CCircle(temp1);
            pc->SetAcreage(pc->CalAcr());
            pShapes[i] = pc;
            break;
        case 'T':case 't':
            cin >> temp1 >> temp2 >> temp3;
            pt = new CTriangle(temp1, temp2, temp3);
            pt->SetAcreage(pt->CalAcr());
            pShapes[i] = pt;
            break;
        
        }
    
    }

    if(n == 1) cout << "共有" << n << "种图形，它是：" << endl;
    else cout << "共有" << n << "种图形, 分别是：" << endl;
    
    for(i = 0; i < n; ++i)
    {
        pShapes[i]->PrintInfo();
        delete pShapes[i]; //释放空间
    }
    return 0;
}
