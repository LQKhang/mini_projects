#include <iostream>
#include <vector>

using namespace std;

class SV
{
  string hoTen;
  float diemToan;
  float diemVan;
  float diemAnh;

public:
  void nhap();
  void xuat();
  double DTB();
  string getHoTen()
  {
    return hoTen;
  }
};

void SV::nhap()
{
  do
  {
    cout << "Nhap ten sv: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap diem toan: ";
    cin >> diemToan;
    cout << "Nhap diem van: ";
    cin >> diemVan;
    cout << "Nhap diem Anh: ";
    cin >> diemAnh;

    if (diemToan < 0 || diemToan > 10 || diemVan < 0 || diemVan > 10 || diemAnh < 0 || diemAnh > 10)
    {
      cout << "Nhap lai!!!!!!" << endl;
    }

  } while (diemToan < 0 || diemToan > 10 ||
           diemVan < 0 || diemVan > 10 ||
           diemAnh < 0 || diemAnh > 10);
}

double SV::DTB()
{
  return (diemToan + diemAnh + diemVan) / 3;
}

void SV::xuat()
{

  cout << "\n\nHo ten: " << hoTen << "\nDiem toan: " << diemToan << "\nDiem van: " << diemVan << "\nDiem anh: " << diemAnh << "\nDiem TB :" << DTB();
}

void xoa(vector<SV> &a)
{
  string name;
  cout << "\nNhap ten sv muon xoa: ";
  cin.ignore();
  getline(cin, name);
  for (int i = 0; i < a.size(); ++i)
  {
    if (name == a[i].getHoTen())
    {
      a.erase(a.begin() + (i));
      return;
    }
  }
}

void them(vector<SV> &b)
{
  cout << "\n--------THEM SV--------------\n";
  SV them_sv;
  them_sv.nhap();
  b.push_back(them_sv);
}
int main()
{
  int n, m;
  cout << "Nhap so luong sv:";
  cin >> n;

  vector<SV> ds(n);
  for (int i = 0; i < n; ++i)
  {
    cout << "------Sinh vien thu " << i + 1 << endl;
    ds[i].nhap();
  }

  cout << "\n--------DS SV--------------";
  for (int i = 0; i < ds.size(); ++i)
  {
    ds[i].xuat();
  }

  do
  {
    cout << "\n\n---------------------";
    cout << "\n\nChon phuong an: \n" << endl;
    cout << "0: Thoat chuong trinh" << endl;
    cout << "1: Them sinh vien" << endl;
    cout << "2: Xoa sinh vien" << endl;
    cin >> m;
    switch (m)
    {
    case 0:
      cout << "\n--------DS SV--------------";
      for (int i = 0; i < ds.size(); ++i)
      {
        ds[i].xuat();
      }
      break;
    case 1:
      them(ds);
      cout << "\n--------DS SV SAU KHI THEM--------------";
      for (int i = 0; i < ds.size(); ++i)
      {
        ds[i].xuat();
      }
      break;

    case 2:
      xoa(ds);
      cout << "\n--------DS SV SAU KHI XOA--------------";
      for (int i = 0; i < ds.size(); ++i)
      {
        ds[i].xuat();
      }
      break;

    default:
      cout << "Nhap sai r" << endl;
      break;
    }
  } while (m != 0);

  return 0;
}
