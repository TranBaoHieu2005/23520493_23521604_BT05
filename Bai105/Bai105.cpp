#include <iostream>
using namespace std;

struct Ngay
{
	int ng;
	int th;
	int nm;
};
typedef struct Ngay NGAY;

void Nhap(NGAY&);
void Xuat(NGAY);
int ktNhuan(NGAY);
int SoNgayToiDaTrongThang(NGAY);
int SoThuTuTrongNam(NGAY);
int SoNgayToiDaTrongNam(NGAY);
int SoThuTu(NGAY);
NGAY TimNgay(int, int);
NGAY TimNgay(int);

int main()
{
	NGAY a;

	Nhap(a);
	cout << "Ngay la: ";
	Xuat(a);

	cout << "\nNgay tiep theo la: ";
	Xuat(TimNgay(SoThuTu(a) + 1));

	return 0;
}

void Nhap(NGAY& x)
{
	cout << "Nhap ngay : ";
	cin >> x.ng;
	cout << "Nhap thang: ";
	cin >> x.th;
	cout << "Nhap nam: ";
	cin >> x.nm;
}

void Xuat(NGAY x)
{
	cout << "\nNgay: " << x.ng;
	cout << "\nThang: " << x.th;
	cout << "\nNam: " << x.nm;
}

int ktNhuan(NGAY x)
{
	if (x.nm % 4 == 0 && x.nm % 100 != 0)
		return 1;
	if (x.nm % 400 == 0)
		return 1;
	return 0;
}

int SoNgayToiDaTrongThang(NGAY x)
{
	int ngaythang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (ktNhuan(x))
		ngaythang[1] = 29;
	return ngaythang[x.th - 1];
}

int SoThuTuTrongNam(NGAY x)
{
	int stt = 0;
	for (int i = 1; i <= x.th - 1; i++)
	{
		NGAY temp = { 1,i,x.nm };
		stt = stt + SoNgayToiDaTrongThang(temp);
	}
	return (stt + x.ng);
}

int SoNgayToiDaTrongNam(NGAY x)
{
	if (ktNhuan(x))
		return 366;
	return 365;
}

int SoThuTu(NGAY x)
{
	int stt = 0;
	for (int i = 1; i < x.nm; i++)
	{
		NGAY temp = { 1,1,i };
		stt = stt + SoNgayToiDaTrongNam(temp);
	}
	return (stt + SoThuTuTrongNam(x));
}


NGAY TimNgay(int nam, int stt)
{
	NGAY temp = { 1,1,nam };
	while (stt - SoNgayToiDaTrongThang(temp) > 0)
	{
		stt = stt - SoNgayToiDaTrongThang(temp);
		temp.th++;
	}
	temp.ng = stt;
	return temp;
}

NGAY TimNgay(int stt)
{
	int nam = 1;
	int sn = 365;
	while (stt - sn > 0)
	{
		stt = stt - sn;
		nam++;
		NGAY temp = { 1,1,nam };
		sn = SoNgayToiDaTrongNam(temp);
	}
	return TimNgay(nam, stt);
}