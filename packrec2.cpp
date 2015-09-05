/*
ID: merlinf1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//1 2
//2 3
//3 4
//4 5

struct RECT
{
	int w;
	int h;
};
RECT rect[4] = {0};
vector<RECT> smallRects;
int minArea = 10000000;

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

void add2smallRects(RECT r)
{
	//sort by h
	vector<RECT>::iterator it = smallRects.begin();
	while(it != smallRects.end())
	{
		if (r.h < it->h)
		{
			smallRects.insert(it, r);
			return;
		}
		else if (r.h == it->h)
		{
			return;
		}

		++it;
	}
	smallRects.insert(it, r);
}

void checkMin(int w, int h)
{
	RECT r;
	//default w > h
	if(w > h)
	{
		r.w = w;
		r.h = h;
	}
	else
	{
		r.w = h;
		r.h = w;
	}
	int area = h*w;
	if (area < minArea)
	{
		smallRects.clear();
		minArea = area;
		smallRects.push_back(r);
	}
	else if (area == minArea)
	{
		add2smallRects(r);
	}
}
void calcArea1(RECT r1, RECT r2, RECT r3, RECT r4)
{
	int w = r1.w+r2.w+r3.w+r4.w;
	int h = max(r1.h, r2.h);
	h = max(h, r3.h);
	h = max(h, r4.h);
	
	checkMin(w,h);
}
void calcArea2(RECT r1, RECT r2, RECT r3, RECT r4)
{
	int w,h;
	w = r1.w+r2.w+r3.w;
	w = max(w, r4.w);
	h = max(r1.h, r2.h);
	h = max(h, r3.h);
	h += r4.h;
	
	checkMin(w,h);
}
void calcArea3(RECT r1, RECT r2, RECT r3, RECT r4)
{
	int w,h;
	w = r1.w+r2.w;
	w = max(w, r4.w);
	w += r3.w;
	
	h = max(r1.h, r2.h);
	h += r4.h;
	h = max(h, r3.h);
	
	checkMin(w,h);
}
void calcArea4(RECT r1, RECT r2, RECT r3, RECT r4)
{
	int w,h;
	w = max(r2.w, r3.w);
	w += r1.w + r4.w;
	
	h = r2.h+r3.h;
	h = max(h, r1.h);
	h = max(h, r4.h);
	
	checkMin(w,h);
}
void calcArea5(RECT r1, RECT r2, RECT r3, RECT r4)
{

}
void calcArea6(RECT r1, RECT r2, RECT r3, RECT r4)
{
	if (r4.h < r3.h)
	{
		return;
	}
	if (r3.w < r1.w)
	{
		return;
	}
	if((r3.w+r4.w) < (r1.w+r2.w))
	{
		return;
	}
	
	int w,h;
	w = max(r1.w+r2.w, r3.w+r4.w);
	//w = max(w, r1.w+r4.w);
	//w = max(w, r2.w+r3.w);

	h = max(r1.h+r3.h, r2.h+r4.h);
	
	checkMin(w,h);
}

void rotation(RECT& r)
{
	int t = r.w;
	r.w = r.h;
	r.h = t;
}
void calcArea(RECT r1, RECT r2, RECT r3, RECT r4, int i, int j, int k, int m)
{
	if(i)
	{
		rotation(r1);
	}
	if(j)
	{
		rotation(r2);
	}
	if(k)
	{
		rotation(r3);
	}
	if(m)
	{
		rotation(r4);
	}
	calcArea1(r1,r2,r3,r4);
	calcArea2(r1,r2,r3,r4);
	calcArea3(r1,r2,r3,r4);
	calcArea4(r1,r2,r3,r4);
	calcArea5(r1,r2,r3,r4);
	calcArea6(r1,r2,r3,r4);
}

void calc(RECT r1, RECT r2, RECT r3, RECT r4)
{
	int count = 2;
	int i, j, k, m;
	for(i = 0; i < count; ++i)
	{
		for(j = 0; j < count; ++j)
		{
			for(k = 0; k < count; ++k)
			{
				for(m = 0; m < count; ++m)
				{
					calcArea(r1, r2, r3, r4, i, j, k, m);
				}
			}
		}
	}
}

int main() 
{
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");

    int count = 4;
	int i, j, k, m;
	for(i = 0; i < count; ++i)
	{
		fin >> rect[i].w >> rect[i].h;
	}

	for(i = 0; i < count; ++i)
	{
		for(j = 0; j < count; ++j)
		{
			if (j == i)
			{
				continue;
			}
			for(k = 0; k < count; ++k)
			{
				if (k == i || k == j)
				{
					continue;
				}
				for(m = 0; m < count; ++m)
				{
					if (m == i || m == j || m == k)
					{
						continue;
					}
					calc(rect[i], rect[j], rect[k], rect[m]);
				}
			}
		}
	}
	


    fout << minArea << endl;
	for (i = 0; i < smallRects.size(); ++i)
	{
		fout << smallRects[i].h << " " << smallRects[i].w << endl;
	}

    return 0;
}

