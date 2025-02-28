﻿#pragma once
#include "Date.h"
#include <string>
#include <fstream>
#include "MuonTra.h"
#include "DauSach.h"
#include "DanhMucSach.h"
#include "mylib.h"


#define UP 72 
#define DOWN 80 
#define RIGHT 77 
#define LEFT 75
#define ENER 13 
#define ESC 27
#define MAX_DS 9000
#define F2 60 
#define F4 62
#define F5 63
#define F1 59
using namespace std;




//=====ĐỘC GIẢ=====
struct docgia
{
	int mathe;
	string ho;
	string ten;
	string phai;
	int trangthaithe; // =0 khoa, =1 hoat dong
	listMT mt; // con trỏ sẽ trỏ đến danh sách các cuốn đã và đang mượn
};


struct node_docgia
{
	docgia data;
	node_docgia* left;
	node_docgia* right;
};
typedef struct node_docgia DOCGIA;
typedef struct node_docgia* TREE_DG;

//=====QUÁ HẠN=====
struct quahan
{
	int ma_doc_gia;
	string ma_sach;
	int so_ngay_quahan;
};

// =========== MẢNG TẠM HIỆN THỊ
struct ds_tamThoi
{
	TREE_DG docGia;
	string ho;
	string ten;
	int soNgayQuaHan;
};
typedef ds_tamThoi DS_TAMTHOI;

// ============ QUEUE
struct bien
{
	TREE_DG giaTri; // queue đang chứa các số nguyên
	struct bien* pNext; // con trỏ liên kết giữa các DATA với nhau
};
typedef struct bien DATA;

// khai báo cấu trúc của queue
struct queue
{
	DATA* pHead; //  con trỏ đầu
	DATA* pTail; // con trỏ cuối 
};
typedef struct queue QUEUE;


// ===================== khai báo hàm

// hàm queue
void KhoiTaoQueue(QUEUE& q); // khởi tạo hàng đợi
DATA* KhoiTaoNodeQueue(TREE_DG x); // khởi tạo data để bỏ vào hàng đợi
bool IsEmpty(QUEUE q); // kiểm tra hàng đợi rỗng hay không
bool Push(QUEUE& q, DATA* p); // bỏ vào cuối hàng đợi
bool Pop(QUEUE& q, TREE_DG& x); // x chính là giá trị cần lấy trong DATA - lấy và xóa giá trị đầu ra khỏi hàng đợi

// MƯỢN TRẢ
void khoiTaoDG(TREE_DG& dsDG);
void khoiTaoMuonTra(listMT& dsMT);
PTR_MT taoNodeMT(muontra x);
bool kiemTraSachDangMuon(TREE_DG p, string ma_sach);
void khoiTaoThongTinMuonSach(muontra& x);
int demSoSachDocGiaDangMuon(TREE_DG t);
bool kiemTraQuaHan(TREE_DG docGia);
void xuatSachMuon(TREE_DG docGia, LIST_DS l);
void xuatThongTinMuonTra(muontra a, string ten_sach, int tungdo);
void AddHead(listMT& listMT, PTR_MT node);
void quanLiMuonTra(TREE_DG dsDG, LIST_DS l, bool viewMuonTra);

// ĐỘC GIẢ
TREE_DG timKiemDocGiaTheoMa(TREE_DG& dsDG, int maDocGia);
void themDG(TREE_DG& dsDG, TREE_DG nodeDocGia);
void chuyenCaySangMang(TREE_DG dsDG, docgia* arr, int& index);
void xuatThongTinDocGia(docgia a, int tungdo);
int SoluongDG(TREE_DG dsDG);
bool xac_nhan(int x, int y, const char* s, string temp); 
void ToMau(int x, int y, string a, bool checkHighLight);
void ToMau2(int x, int y, int a, bool checkHighLight);
void ToMau3(int x, int y, Date a, bool checkHighLight);
void duyetCay(TREE_DG ds_docGia, DS_TAMTHOI* nodes[], int& n);
int themDocGia(TREE_DG& dsDG);
int gioiTinh(int x, int y, string gioiTinhHienTai);
void timKiemPhanTuTheMang(TREE_DG& canXoa, TREE_DG& theMang);
int timKiemDocGiaTheoTen(DS_TAMTHOI* arr[], string tuKhoa, int soLuongDG, TREE_DG dsDG, int statusGiaoDien);
void swapDocGia(DS_TAMTHOI*& tamThoi1, DS_TAMTHOI*& tamThoi2);
void sapXepTheoTen(DS_TAMTHOI* arr[], int slDG);
void xoaDocGia(TREE_DG& dsDG, int maDocGia);
void xoaMotDocGia(TREE_DG& dsDG, int maDocGia);
int hieuChinhDocGia(TREE_DG& dsDG, int ma);
void inMotTrangDG(DS_TAMTHOI* list[], int StartIndex, int soLuongDG, int statusGiaoDien);
int menuDocGia(DS_TAMTHOI* list[], int soLuongDG, int& viTriDG, int statusGiaoDien);
void dieuChinhDocGia(TREE_DG& dsDG, bool checkXepTheoTen); // thao tác trực tiếp với độc giả
int xuatDanhSachDocGia(TREE_DG dsDG, bool checkXepTheoTen); // xuất riêng bên mượn trả
void hienThongTin1DG(docgia docgia);
int nhapDSDG(TREE_DG& dsDG, int flag, int ma);
void xoaHuongDan();
int trangThaiDocGia(int x, int y, int trangThaiHienTai);
void checkSachDaTungMuon(TREE_DG dsDG, string maSach, bool& check);
bool kiemTraSachDangDaMuonCuaMotDocGia(TREE_DG p, string ma_sach);
void xoaXacNhan();
void sapXepTheoNgayQuaHan(DS_TAMTHOI* arr[], int slDG);
void duyetCayQuaHan(TREE_DG ds_docGia, DS_TAMTHOI* nodes[], int& n);
void xoaThongTin1DG();
void giaiphong_cay(TREE_DG& dsDG);

//DOC VA GHI FILE
void docFileDG(TREE_DG& dsDG);
void ghiFileDanhSachDocGia(TREE_DG t);
void ghiFileDocGia(TREE_DG q, ofstream& fileout);
int demTongSoSachDocGiaTungMuon(docgia x);

//Khai bao ham ve dau sach va sach
void menuXemDanhMucSach(PTR_DMS& First, int& slsach, bool& ktxoasua, TREE_DG dsDG);
void menuDauSach(LIST_DS& l, TREE_DG dsDG);
int timKiemDSTheoTen(LIST_DS& l, string tuKhoa, int flag, string& masach, int& ktxoasua, int& slDSThem, TREE_DG dsDG);

// ===================== triển khai hàm

void khoiTaoDG(TREE_DG& dsDG)
{
	dsDG = NULL;
}
// khởi tạo node mượn trả
PTR_MT taoNodeMT(muontra x)
{
	PTR_MT nodeMT = new node_muontra;
	nodeMT->data = x;
	nodeMT->next = NULL;

	return nodeMT;
}
// khởi tạo ds mượn trả
void khoiTaoMuonTra(listMT& dsMT)
{
	dsMT.pHead = NULL;
}

// số lượng sách độc giả đã và đang mượn
int demTongSoSachDocGiaTungMuon(docgia x)
{
	int n = 0;
	for (PTR_MT p = x.mt.pHead; p != NULL; p = p->next)
		n++;
	return n;
}
// GHI FILE ĐỘC GIẢ
void ghiFileDanhSachDocGia(TREE_DG t)
{
	ofstream fileout("DOCGIA.txt");
	int n = SoluongDG(t);
	fileout << n << endl;
	ghiFileDocGia(t, fileout);
	fileout.close();
}
// ĐẠO HÀM GHI THÔNG TIN ĐỘC GIẢ VÀO FILE
void ghiFileDocGia(TREE_DG nodeDocGia, ofstream& fileout)
{

	QUEUE bf_queue;
	KhoiTaoQueue(bf_queue);

	Push(bf_queue, KhoiTaoNodeQueue(nodeDocGia));
	if (IsEmpty(bf_queue) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
		return;
	}
	while (IsEmpty(bf_queue) == false)
	{
		TREE_DG current;
		Pop(bf_queue, current); // lấy phần tử đầu và xóa khởi hàng đợi
		// GHI VÀO FILE ĐỘC GIẢ HIỆN TẠI
		fileout << current->data.mathe << ',';
		fileout << current->data.ho << ',';
		fileout << current->data.ten << ',';
		fileout << current->data.phai << ',';
		fileout << current->data.trangthaithe << endl;
		fileout << demTongSoSachDocGiaTungMuon(current->data) << endl;
		for (PTR_MT p = current->data.mt.pHead; p != NULL; p = p->next)
		{
			fileout << p->data.masach << ',';
			fileout << p->data.trangthai << ',';
			fileout << p->data.ngaymuon.ngay << '/';
			fileout << p->data.ngaymuon.thang << '/';
			fileout << p->data.ngaymuon.nam << ',';
			fileout << p->data.ngaytra.ngay << '/';
			fileout << p->data.ngaytra.thang << '/';
			fileout << p->data.ngaytra.nam << endl;
		}

		/* Enqueue con trái và con phải của current vào bf_queue.*/
		if (current->left != NULL) {
			/*bf_queue.push(current->left);*/
			Push(bf_queue, KhoiTaoNodeQueue(current->left));
		}
		if (current->right != NULL) {
			/*bf_queue.push(current->right);*/
			Push(bf_queue, KhoiTaoNodeQueue(current->right));
		}
		
	}

	
	
}
// ĐỌC FILE ĐỘC GIẢ
void docFileDG(TREE_DG& dsDG)
{
	ifstream f("DOCGIA.txt", ios::in);
	muontra muonTra;
	docgia docGia;
	int n = 0;
	int temp = 0;
	f >> n;
	for (int j = 0; j < n; j++)
	{
		f >> docGia.mathe;
		f.ignore();
		getline(f, docGia.ho, ',');
		getline(f, docGia.ten, ',');
		getline(f, docGia.phai, ',');
		f >> docGia.trangthaithe;
		f.ignore();
		f >> temp;
		f.ignore();
		// khởi tạo nocde độc giả
		DOCGIA* nodeDocGia = new DOCGIA;
		nodeDocGia->data = docGia;
		nodeDocGia->left = nodeDocGia->right = NULL;
		khoiTaoMuonTra(nodeDocGia->data.mt); // khoi tao danh sach muon tra

		themDG(dsDG, nodeDocGia); // thêm node độc giả vào danh sách


		for (int i = 0; i < temp; i++)
		{
			getline(f, muonTra.masach, ',');
			f >> muonTra.trangthai;      f.ignore();
			f >> muonTra.ngaymuon.ngay;  f.ignore();
			f >> muonTra.ngaymuon.thang; f.ignore();
			f >> muonTra.ngaymuon.nam;   f.ignore();
			f >> muonTra.ngaytra.ngay;   f.ignore();
			f >> muonTra.ngaytra.thang;  f.ignore();
			f >> muonTra.ngaytra.nam;    f.ignore();
			AddHead(nodeDocGia->data.mt, taoNodeMT(muonTra));
		}
	}
	f.close();
}

// thêm một độc giả vào cây
void themDG(TREE_DG& dsDG, TREE_DG nodeDocGia)
{
	if (dsDG == NULL)
	{
		dsDG = nodeDocGia;
	}
	else
	{
		if (nodeDocGia->data.mathe < dsDG->data.mathe)
			themDG(dsDG->left, nodeDocGia);
		else if (nodeDocGia->data.mathe > dsDG->data.mathe)
			themDG(dsDG->right, nodeDocGia);
	}
}


// thêm mượn trả
void AddHead(listMT& listMT, PTR_MT node)
{
	if (listMT.pHead == NULL)
	{
		listMT.pHead = node;
	}
	else
	{
		node->next = listMT.pHead;
		listMT.pHead = node;
	}
}

// xuất danh sách độc giả
int xuatDanhSachDocGia(TREE_DG dsDG, bool checkXepTheoTen)
{
	int n = SoluongDG(dsDG); // số lượng độc giả trong mảng
	int t_sotrang = (n - 1) / 40 + 1;
	DS_TAMTHOI *arr[MAX_DS] ; // khai bao mảng bằng số lượng độc giả
	int index = 0; // số lượng phần tử trong mảng
	duyetCay(dsDG, arr, index);

	if (checkXepTheoTen == true)
	{
		sapXepTheoTen(arr, n);
	}
	int tungdo = 1; // dòng đâu tiên trong danh sách
	for (int i = 0; i < t_sotrang; i++)
	{
		for (int j = i * 40; j < (40 * i) + 40 && j < n && tungdo < 40; j++)
			xuatThongTinDocGia(arr[j]->docGia->data, tungdo++); 

		gotoxy(105, 42); cout << i + 1 << "/" << t_sotrang;


	
		char c = _getch();
		if (c == -32 || c == 0 )
			c = _getch();
		if (c == 77)
		{
	
			tungdo = 1;
			if (i == t_sotrang - 1)
				i = -1;
		}
		else if (c == 75)
		{

			tungdo = 1;
			if (i == 0)
				i = t_sotrang - 2;
			else
			{
				i -= 2;
				continue;
			}
		}
		if (c == F2)
		{
			return F2;
		}
		if (c == F4)
		{
			return F4;
		}
		if (c == F1)
		{
			return F1;
		}
		if (c == ESC)
		{
			return ESC;
		}
		if (c == ENTER)
		{
			return ENTER;
		}
		else
		{

			delete[] arr;
			return 0;
		}
	}
	delete[] arr;
	return 0;
}
// đếm số đọc giả trong cây
int SoluongDG(TREE_DG dsDG)
{
	int n = 1;
	if (dsDG)
	{
		n += SoluongDG(dsDG->left);
		n += SoluongDG(dsDG->right);
		return n;
	}
	else return 0;
}
// duyệt cây copy dữ liệu vào mảng
void chuyenCaySangMang(TREE_DG dsDG, docgia* arr, int& index)
{
	if (dsDG != NULL)
	{
		chuyenCaySangMang(dsDG->left, arr, index);
		arr[index++] = dsDG->data;
		chuyenCaySangMang(dsDG->right, arr, index);
	}// nếu cây rỗng thoát hàm
	else
		return;
}
// Xuất thông tin của 1 độc giả
void xuatThongTinDocGia(docgia a, int tungdo)
{
	int x = wherex();
	int y = wherey();
	SetColor(14);
	gotoxy(50, 0);
	cout << "MA DOC GIA";
	gotoxy(65, 0);
	cout << "HO";
	gotoxy(90, 0);
	cout << "TEN";
	gotoxy(120, 0);
	cout << "PHAI";
	gotoxy(135, 0);
	cout << "TRANG THAI THE";
	NormalLine();
	gotoxy(50, tungdo);
	cout << a.mathe;
	gotoxy(65, tungdo);
	cout << a.ho;
	gotoxy(90, tungdo);
	cout << a.ten;
	gotoxy(120, tungdo);
	cout << a.phai;
	gotoxy(137, tungdo);
	if (a.trangthaithe == 1)
		cout << "HOAT DONG";
	else
		cout << "KHOA";
	SetColor(7);
	gotoxy(x, y);
}
// tìm kiếm độc giả trong danh sách với mã độc giả
TREE_DG timKiemDocGiaTheoMa(TREE_DG& dsDG, int maDocGia)
{
	if (dsDG != NULL)
	{
		if (dsDG->data.mathe == maDocGia)
			return dsDG;
		else if (dsDG->data.mathe < maDocGia)
			return timKiemDocGiaTheoMa(dsDG->right, maDocGia);
		else
			return timKiemDocGiaTheoMa(dsDG->left, maDocGia);
	}
	else
		return NULL;
}
void xuatSachMuon(TREE_DG docGia, LIST_DS l)
{
	int kt = 0; // kiểm tra nếu độc giả có sách đang mượn thì tăng. nếu không có sách đang mượn =0
	int tungdo = 32;
	SetColor(15);
	int x = wherex();
	int y = wherey();
	gotoxy(45, tungdo);
	cout << "Ma Sach";
	gotoxy(60, tungdo);
	cout << "Ten Sach";
	gotoxy(100, tungdo);
	cout << "Ngay Muon";
	gotoxy(130, tungdo);
	cout << "Ngay Tra";
	gotoxy(160, tungdo);
	cout << "Trang Thai";
	for (PTR_MT p = docGia->data.mt.pHead; p != NULL; p = p->next)
	{
		for (int i = 0; i < l.n; i++)
		{
			if (l.ds[i]->ISBN == tachMaSach(p->data.masach)) {
				if (p->data.trangthai == 0 || p->data.trangthai == 2)
				{
					kt++;
					xuatThongTinMuonTra(p->data, l.ds[i]->tensach, ++tungdo);
				}
			}
		}
	}	

}

// in thong tin của 1 phiếu mượn trả
void xuatThongTinMuonTra(muontra a, string ten_sach, int tungdo)
{
	SetColor(15);
	int x = wherex();
	int y = wherey();
	/*
	gotoxy(45, 0);
	cout << "Ma Sach";
	gotoxy(60, 0);
	cout << "Ten Sach";
	gotoxy(100, 0);
	cout << "Ngay Muon";
	gotoxy(130, 0);
	cout << "Ngay Tra";
	gotoxy(160, 0);
	cout << "Trang Thai";
	*/
	gotoxy(45, tungdo);
	cout << a.masach;
	gotoxy(60, tungdo);
	cout << ten_sach;
	gotoxy(100, tungdo);
	cout << a.ngaymuon.ngay << "/" << a.ngaymuon.thang << "/" << a.ngaymuon.nam;
	gotoxy(130, tungdo);
	cout << a.ngaytra.ngay << "/" << a.ngaytra.thang << "/" << a.ngaytra.nam;
	gotoxy(160, tungdo);
	if (a.trangthai == 0)
		cout << "DANG MUON";
	else if (a.trangthai == 1)
		cout << "DA TRA";
	else
		cout << "LAM MAT";
	gotoxy(x, y);
	SetColor(7);
}

// Muon sach
void MUON_SACH(TREE_DG& t, LIST_DS& l, TREE_DG& nodeDG)
{
	int bienThaoTac = 0; // biến kiem tra ESC cua ham nhap
	int dem; // dem sách độc giả đang mượn
	int sldausach = 0;
	while (1)
	{
		dem = 0;

		

		if (nodeDG->data.trangthaithe == 0) // thẻ bị khóa
		{
			inThongBao("THE DOC GIA BI KHOA.TRA SACH DE TIEP TUC");
			Sleep(1000);
			xoaThongBao();
			break;
		}
		if (kiemTraQuaHan(nodeDG) == true) // độc giả mượn sách quá hạn
		{
			
			inThongBao("DOC GIA MUON SACH QUA HAN. KHONG THE MUON");
			Sleep(1000);
			xoaThongBao();
			break;
		}

		dem = demSoSachDocGiaDangMuon(nodeDG); // kiểm tra số lượng sách độc giả đã mượn nếu > 3 không mượn được
		if (dem >= 3)
		{
			
			inThongBao("! DOC GIA MUON QUA 3 CUON. !TRA SACH DE MUON THEM");
			Sleep(1000);
			xoaThongBao();
			break;
		}
		else if(dem == 0){
			inThongBao("HIEN TAI DOC GIA CHUA MUON SACH");
			Sleep(1000);
			xoaThongBao();
		}
		PTR_DMS k = NULL;
		string ten_sach;
		string ma_dau_sach;
		string masach; //mã sách được chọn để mượn
		int kt;

		int indexDS = 0;
		gotoxy(99, 42); cout << "                         ";
		while (1) // vòng while dừng khi số lượng sách hơn 3 hoặc nhấn phím ESC
		{			
			bool check = false; // kiem tra co tim thay ma sach hay ko
			if (dem >= 3) break; // mượn đến khi nào sách bằng 3 cuốn thì dừng 
			system("cls");
			gotoxy(20, 5);
			cout << "CHE DO MUON SACH";
			xuatSachMuon(nodeDG, l);
			ten_sach = ""; // mỗi lần nhập là reset tên và mã sách
			masach = "";
			gotoxy(35, 30);
			cout << "NHAP TEN SACH: ";
			bienThaoTac = nhap_ki_tu(ten_sach, 1 , 0, 0);			

			if (bienThaoTac == -1) // ESC 
				return;

			sldausach = timKiemDSTheoTen(l, ten_sach, 1, masach, kt, kt, t);
			ShowCur(false);
			if (sldausach == 0)
			{
				xoaThongBao();
				inThongBao("Khong tim thay dau sach thich hop!");
				Sleep(1000);
				xoaThongBao();
				continue;
			}
			if (masach.compare("") == 0)
			{
				continue;
			}
			if (xac_nhan(80, 40, "XAC NHAN MUON SACH NAY", "") == false)
			{
				continue;
			}
			
			bool checkExistDMS = false;
			ma_dau_sach = tachMaSach(masach); // tách mã sách thành mã đầu sách
			indexDS = timKiemDauSachTheoMa(l, ma_dau_sach); // tìm kiếm sách theo mã trả về vị trí của đầu sách
			if (indexDS == -1) // khoong tim thay
			{

				inThongBao("MA SACH KHONG DUNG");
				Sleep(1000);
				xoaThongBao();
				continue;
			}
			else // tim thay lay vi tri cua i
			{
				if (kiemTraSachDangMuon(nodeDG, masach) == true) // ĐANG MƯỢN SÁCH THUỘC ĐS TƯƠNG TỰ
				{
					
					inThongBao("DOC GIA DANG MUON SACH NAY");
					Sleep(1000);
					xoaThongBao();
					continue;
				}
				// TRƯỜNG HỢP TÌM RA SÁCH NHƯNG KO CÓ BẢN DANH MỤC SÁCH MÀ CHI CÓ MỖI ĐẦU SÁCH
				if (l.ds[indexDS]->dms == NULL) {
					
					inThongBao("SACH NAY CHI CON BAN GOC, VUI LONG MUON SACH KHAC");
					Sleep(1000);
					xoaThongBao();
					continue;
				}
				for (k = l.ds[indexDS]->dms; k != NULL; k = k->next) // vòng lặp kiểm tra tình trạng sách và cập nhật tình trạng sách
				{
					if (k->data.masach == masach)
					{
						if (k->data.trangthai == 0)
						{
							dem++; // thay đổi số lượng sách mượn để tí nữa kiểm tra 
							check = true; // đánh dấu là mượn thành công để chuẩn bị vào bước ghi file lưu thông tin
							k->data.trangthai = 1; // cap nhat sach co nguoi muon
						
							break;
						}
						else if (k->data.trangthai == 1)
						{
							
							inThongBao("SACH DA CO NGUOI MUON");
							Sleep(1000);
							xoaThongBao();
							break;
						}
						else if (k->data.trangthai == 2)
						{
							
							inThongBao("SACH DA THANH LI");
							Sleep(1000);
							xoaThongBao();
							break;
						}
					}
				}
				
				if (check == true)
				{
					// -------------- cập nhật thông tin mượn trả ----------
					muontra x;  // khai báo một struct mượn trả
					x.masach = masach;
					l.ds[indexDS]->soluotmuon++; // tăng số lượng mượn cuốn sách
					khoiTaoThongTinMuonSach(x); // khởi tạo thông tin mượn trả
					AddHead(nodeDG->data.mt, taoNodeMT(x)); // tạo node mượn trả rồi thêm vào cuối
					inThongBao("MUON THANH CONG"); // thông báo thêm thành công 
					ShowCur(false);
					Sleep(1000);
					xoaThongBao();
					//GhiFileDS(l); // ghi lại gile cập nhật độc giả mượn sách
					//GHI_FILE_DS_DG(t); // ghi lại file cập nhật sách đã có người mượn
				}
				

			}
		}
	}
}


// kiem tra xem doc gia co muon sach qua han hay ko neu qua han rt true <> false
bool kiemTraQuaHan(TREE_DG docGia)
{
	int n = 0;
	for (PTR_MT q = docGia->data.mt.pHead; q != NULL; q = q->next)
	{
		if (q->data.trangthai == 0) // dang muon sach
		{
			n = tinhSoNgay(q->data.ngaymuon);
			if (n >= 7)
				return true;
		}
	}
	return false;
}

// đếm số sách độc giả đang mượn dùng để kiểm tra điều kiện mượn sách ( chỉ đếm sách có tình trạng đang đọc)
int demSoSachDocGiaDangMuon(TREE_DG t)
{
	int so_sach_muon = 0;
	for (PTR_MT p = t->data.mt.pHead; p != NULL; p = p->next)
	{
		if (p->data.trangthai == 0 || p->data.trangthai == 2) // sách chưa trả
			so_sach_muon++;
	}
	return so_sach_muon;
}

bool kiemTraSachDangMuon(TREE_DG p, string ma_sach)
{
	string s = tachMaSach(ma_sach);
	string temp;
	for (PTR_MT q = p->data.mt.pHead; q != NULL; q = q->next)
	{
		if (q->data.trangthai == 0) // đang mượn sách
		{
			temp = tachMaSach(q->data.masach);
			if (temp == s) // đang mượn cuốn sách có đầu sách tương tự
				return true;
		}
	}
	return false;
}

// lập phiếu mượn sách
void khoiTaoThongTinMuonSach(muontra& x)
{
	// phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
	thoiGianThuc(x.ngaymuon);
	x.ngaytra.ngay = 0;
	x.ngaytra.thang = 0;
	x.ngaytra.nam = 0;
	x.trangthai = 0; // trạng thái mặc định =0 độc giả đang mượn cuốn sách
}

void traSach(TREE_DG docGia, LIST_DS l, bool modeTraSach)
{
	GO:
	system("cls"); // xoá màn hình
	NormalLine();
	gotoxy(20, 5);
	cout << (modeTraSach == true ? "CHE DO TRA SACH" : "CHE DO MAT SACH");
	gotoxy(45, 0);
	cout << "Ma Sach";
	gotoxy(60, 0);
	cout << "Ten Sach";
	gotoxy(100, 0);
	cout << "Ngay Muon";
	gotoxy(130, 0);
	cout << "Ngay Tra";
	gotoxy(160, 0);
	cout << "Trang Thai";
	int phimThaoTac;
	int n = demSoSachDocGiaDangMuon(docGia);
	if (n < 1)
	{
		inThongBao(modeTraSach == true ? " CHUA MUON SACH MA DOI TRA" : "CHUA MUON SACH MA DOI MAT");
		Sleep(1000);
		xoaThongBao();
		return;
	}
	bool check = false;
	muontra* arr = new muontra[n];
	int indexNow = 0;
	int indexArr = 0;
	for (PTR_MT p = docGia->data.mt.pHead; p != NULL; p = p->next)
	{
		if (p->data.trangthai == 0 || p->data.trangthai == 2)
		{
			arr[indexArr++] = p->data;
		}
	}
	
				
				for (int i = 0; i < n; i++) {  
					string temp = tachMaSach(arr[i].masach); // tách mã sách thành mã đầu sách 
					int index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng
					ToMau(45, i + 1, arr[i].masach, false); // tô màu mã sách
					ToMau3(100, i + 1, arr[i].ngaymuon, false);// tô màu ngày
					ToMau3(130, i + 1, arr[i].ngaytra, false);// tô màu ngày
					ToMau(60, i + 1, l.ds[index]->tensach, false); // to mau ten sACH
					if (arr[i].trangthai == 0) {
						ToMau(160, i + 1, "DANG MUON", false);
					}
					else if (arr[i].trangthai == 1) {
						ToMau(160, i + 1, "DA TRA", false);
					}
					else
						ToMau(160, i + 1, "LAM MAT", false);
					
				}


				string temp = tachMaSach(arr[indexNow].masach); // tách mã sách thành mã đầu sách 
				int index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng		
				ToMau(45, indexNow + 1, arr[indexNow].masach, true); // tô màu mã sách
				ToMau3(100, indexNow + 1, arr[indexNow].ngaymuon, true);// tô màu ngày
				ToMau3(130, indexNow + 1, arr[indexNow].ngaytra, true);// tô màu ngày

				ToMau(60, indexNow +1, l.ds[index]->tensach, true); // to mau ten sACH
				if (arr[indexNow].trangthai == 0) {
					ToMau(160, indexNow + 1, "DANG MUON", true);
				}
				else if (arr[indexNow].trangthai == 1) {
					ToMau(160, indexNow + 1, "DA TRA", true);
				}
				else
					ToMau(160, indexNow + 1, "LAM MAT", true);
				int signal;
				while (true)
				{
					while (_kbhit)
					{
						signal = _getch();
						if (signal == ESC)
							return ;
						if (signal == 224);
							if (signal == ENTER)
							{
								
									// kiểm tra sách này đã được bật trạng thái mất hay chưa?
									bool kiemTraMatSach = false;
									for (PTR_MT p = docGia->data.mt.pHead; p != NULL; p = p->next) {
										if (p->data.masach == arr[indexNow].masach) {
											if (p->data.trangthai == 2 && modeTraSach == false) {
												inThongBao("SACH NAY DA BI MAT TRUOC DO");
												Sleep(1000);
												xoaThongBao();
												kiemTraMatSach = true;
											}


										}

									}
									if (kiemTraMatSach == true) {
										continue;
									}

									// hộp thoại xác nhận trả hoặc mất sách
									if (xac_nhan(80, 15, modeTraSach == true ? "XAC NHAN TRA SACH " : "XAC NHAN MAT SACH ", arr[indexNow].masach) == true)
										check = true;
									else check = false;
									xoaXacNhan();
									if (check) {
										if (modeTraSach == true) {
											int dem = 0;
											PTR_DMS dms = timKiemDanhMucSach(l, arr[indexNow].masach);
											for (PTR_MT p = docGia->data.mt.pHead; p != NULL; p = p->next) {
												if (p->data.masach == arr[indexNow].masach) {
													p->data.trangthai = 1;
													dms->data.trangthai = 0;
													thoiGianThuc(p->data.ngaytra);
												}
												if (p->data.trangthai == 2) dem++;
											}
											if (dem != 0) // còn sách làm mất -> khóa thẻ
												docGia->data.trangthaithe = 0;
											else
												docGia->data.trangthaithe = 1; // mở thẻ nếu trả được sách đã mất


										}
										else {
											PTR_DMS dms = timKiemDanhMucSach(l, arr[indexNow].masach);
											if (dms == NULL) {
												inThongBao("SACH NAY CHI CO BAN GOC");
												Sleep(1000);
												xoaThongBao();
											}
											for (PTR_MT p = docGia->data.mt.pHead; p != NULL; p = p->next) {
												if (p->data.masach == arr[indexNow].masach) {
													if (p->data.trangthai == 2) {
														inThongBao("SACH NAY DA MAT TRUOC DO");
														Sleep(1000);
														xoaThongBao();
													}
													else {
														p->data.trangthai = 2;
														dms->data.trangthai = 2;
														docGia->data.trangthaithe = 0;
													}

												}

											}
										}
									}								
									goto GO;
							}

						
							else if (signal == UP)
							{

								if (indexNow > 0)
								{
									
									
									temp = tachMaSach(arr[indexNow].masach); // tách mã sách thành mã đầu sách 
									index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng
									ToMau(45, indexNow + 1, arr[indexNow].masach, false); // tô màu mã sách
									ToMau3(100, indexNow + 1, arr[indexNow].ngaymuon, false);// tô màu ngày
									ToMau3(130, indexNow + 1, arr[indexNow].ngaytra, false);// tô màu ngày
									ToMau(60, indexNow + 1, l.ds[index]->tensach, false); // to mau ten sACH
									if (arr[indexNow].trangthai == 0) {
										ToMau(160, indexNow + 1, "DANG MUON", false);
									}
									else if (arr[indexNow].trangthai == 1) {
										ToMau(160, indexNow + 1, "DA TRA", false);
									}
									else
										ToMau(160, indexNow + 1, "LAM MAT", false);

									indexNow-=1;

									temp = tachMaSach(arr[indexNow].masach); // tách mã sách thành mã đầu sách 
									index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng
									ToMau(45, indexNow + 1, arr[indexNow].masach, true); // tô màu mã sách
									ToMau3(100, indexNow + 1, arr[indexNow].ngaymuon, true);// tô màu ngày
									ToMau3(130, indexNow + 1, arr[indexNow].ngaytra, true);// tô màu ngày
									ToMau(60, indexNow + 1, l.ds[index]->tensach, true); // to mau ten sACH
									if (arr[indexNow].trangthai == 0) {
										ToMau(160, indexNow + 1, "DANG MUON", true);
									}
									else if (arr[indexNow].trangthai == 1) {
										ToMau(160, indexNow + 1, "DA TRA", true);
									}
									else
										ToMau(160, indexNow + 1, "LAM MAT", true);

									
								}

							}
							else if (signal == DOWN)
							{
							if (indexNow < n - 1)
							{
								temp = tachMaSach(arr[indexNow].masach); // tách mã sách thành mã đầu sách 
								index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng
								ToMau(45, indexNow + 1, arr[indexNow].masach, false); // tô màu mã sách
								ToMau3(100, indexNow + 1, arr[indexNow].ngaymuon, false);// tô màu ngày
								ToMau3(130, indexNow + 1, arr[indexNow].ngaytra, false);// tô màu ngày
								ToMau(60, indexNow + 1, l.ds[index]->tensach, false); // to mau ten sACH
								if (arr[indexNow].trangthai == 0) {
									ToMau(160, indexNow + 1, "DANG MUON", false);
								}
								else if (arr[indexNow].trangthai == 1) {
									ToMau(160, indexNow + 1, "DA TRA", false);
								}
								else
									ToMau(160, indexNow + 1, "LAM MAT", false);

								indexNow += 1;

								temp = tachMaSach(arr[indexNow].masach); // tách mã sách thành mã đầu sách 
								index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng
								ToMau(45, indexNow + 1, arr[indexNow].masach, true); // tô màu mã sách
								ToMau3(100, indexNow + 1, arr[indexNow].ngaymuon, true);// tô màu ngày
								ToMau3(130, indexNow + 1, arr[indexNow].ngaytra, true);// tô màu ngày
								ToMau(60, indexNow + 1, l.ds[index]->tensach, true); // to mau ten sACH
								if (arr[indexNow].trangthai == 0) {
									ToMau(160, indexNow + 1, "DANG MUON", true);
								}
								else if (arr[indexNow].trangthai == 1) {
									ToMau(160, indexNow + 1, "DA TRA", true);
								}
								else
									ToMau(160, indexNow + 1, "LAM MAT", true);
							}
							
							}

					}
						
				}

				
					


}
// XÁC NHẬN mượn trả
bool xac_nhan(int x, int y, const char* s, string temp)
{
	char c;
	// hiện khung xác nhận trả sach

	gotoxy(x, y);
	cout << s << ": " << temp;

	while (1)
	{
		// hiện thị đang ở lưa chọn có
		ToMau(x + 25, y + 2, "CO",true);
		ToMau(x + 30, y + 2, "HUY",false);
		c = _getch();
		// nếu nhấn enter thì trả về true để xóa
		if (c == 13) {
		
			return true;
		}
		else if (c == 27)
		{
			
			return false;
		}
		if (c == -32) c = _getch();
		if (c == 77 || c == 75)
		{
			// nhấn di chuyển thì chuyển qua hủy ( nếu tiếp tục di chuyển thì quay về vòng lặp)
			ToMau(x + 25, y + 2, "CO", false);
			ToMau(x + 30, y + 2, "HUY", true);
			c = _getch(); if (c == -32) c = _getch();
			if (c == 13 || c == 27) {
				system("cls");
				return false;
			}
		}
	}
}

// các hàm tô màu thông tin mượn và mất sách
void ToMau(int x, int y, string a, bool checkHighLight)
{
	if (checkHighLight == true)
	{
		/*SetColor(color);*/
		HighlightLine();
		gotoxy(x, y);
		cout << a;
		/*SetColor(7);*/
		NormalLine();
	}
	else {
		NormalLine();
		gotoxy(x, y);
		cout << a;
	}
	//SetColor(color);
	//gotoxy(x, y);
	//cout << a;
	//SetColor(7);
}
void ToMau2(int x, int y, int a, bool checkHighLight)
{
	
	if (checkHighLight == true)
	{
		/*SetColor(color);*/
		HighlightLine();
		gotoxy(x, y);
		cout << a;
		/*SetColor(7);*/
		NormalLine();
	}
	else {
		NormalLine();
		gotoxy(x, y);
		cout << a;
		/*SetColor(7);*/
	}
}
void ToMau3(int x, int y, Date a, bool checkHighLight)
{

	if (checkHighLight == true)
	{
		/*SetColor(color);*/
		HighlightLine();
		gotoxy(x, y);
		cout << a.ngay << "/" << a.thang << "/" << a.nam;
		/*SetColor(7);*/
		NormalLine();
	}
	else {
		NormalLine();
		gotoxy(x, y);
		cout << a.ngay << "/" << a.thang << "/" << a.nam;
		/*SetColor(7);*/
	}
	//SetColor(color);
	//gotoxy(x, y);
	//cout << a.ngay << "/" << a.thang << "/" << a.nam;
	//SetColor(7);
}

// -------------- duyệt cây theo NLR và đưa vào mảng
void duyetCay(TREE_DG ds_docGia, DS_TAMTHOI* nodes[], int& n)
{
	if (ds_docGia != NULL)
	{
		duyetCay(ds_docGia->left, nodes, n);
		nodes[n] = new DS_TAMTHOI;
		nodes[n]->docGia = ds_docGia;
		nodes[n]->ho = ds_docGia->data.ho;
		nodes[n]->ten = ds_docGia->data.ten;
		n++;
		duyetCay(ds_docGia->right, nodes, n);
	}
}

// thêm độc giả
int themDocGia(TREE_DG &dsDG)
{
	
	
		
		xoaHuongDan();
		xoaThongTin1DG();
		gotoxy(20, 20);
		NormalLine();
		cout << "DANG O CHE DO THEM DOC GIA -- NHAN ESC DE THOAT";
		int i = nhapDSDG(dsDG, 0, 0);
		return i;
	


}


// lựa chọn giới tính
int gioiTinh(int x, int y, string gioiTinhHienTai)
{
	ShowCur(false);
	char c;
	// hiện khung xác nhận trả sach
	if (gioiTinhHienTai == "NU")
		goto NU;
	gotoxy(x, y);
	cout << "GIOI TINH: ";

	while (1)
	{
		// hiện thị đang ở lưa chọn có
		/*gotoxy(x + 15, y ); SetColor(252); cout << "NAM";	
		gotoxy(x + 20, y); SetColor(247); cout << "NU";*/
		ToMau(x + 15, y, "NAM", true);
		ToMau(x + 20, y, "NU", false);
		
		c = _getch();
		// nếu nhấn enter thì trả về true để xóa
		if (c == 13) {

			return 1;
		}
		else if (c == 27)
		{

			return -1;
		}
		if (c == -32) c = _getch();
		if (c == 77 || c == 75)
		{
			NU:
			// nhấn di chuyển thì chuyển qua hủy ( nếu tiếp tục di chuyển thì quay về vòng lặp)
			/*gotoxy(x + 15, y ); SetColor(247); cout << "NAM";
			gotoxy(x + 20, y ); SetColor(252); cout << "NU";*/
			ToMau(x + 15, y, "NAM", false);
			ToMau(x + 20, y, "NU", true);
			c = _getch(); if (c == 0 || c == -32) c = _getch();
			if (c == 13 ) {				
				return 2;
			}
			else if (c == 27) {
				NormalLine();
				return -1;
			}
			else if (c == UP)
			{
				return UP;
			}
			else if (c == DOWN)
			{
				return DOWN;
			}
		}
		else if (c == UP || c == DOWN) {
			if (c == UP)
			{
				return UP;
			}
			else if (c == DOWN)
			{
				return DOWN;
			}
		}
	}
}

// quản lí mượn, trả và mất sách 
void quanLiMuonTra(TREE_DG dsDG, LIST_DS l,bool viewMuonTra)
{
viTri:
	int bienThaoTac = 0; // biến kiem tra ESC cua ham nhap
	int maDocGia = 0; // mã độc giả dạng số
	TREE_DG nodeDG;// lưu  độc giả tìm được

	int viTriDG = 0;
	DS_TAMTHOI* arr[MAX_DS]; // khai bao mảng bằng số lượng độc giả
	int index = 0; // số lượng phần tử trong mảng
	if (viewMuonTra == true)
	{
		duyetCay(dsDG, arr, index);
	}
	else {
		duyetCayQuaHan(dsDG, arr, index); 
		sapXepTheoNgayQuaHan(arr, index);
	}
	
	int soLuongDG = SoluongDG(dsDG);
	
	int thaoTacChucNang = menuDocGia(arr, index, viTriDG, 2);

	while (true)
	{

		if (thaoTacChucNang == ESC)
		{
			return;
		}
		if (thaoTacChucNang == F1)
		{
			string tenDocGia = "";  // mã độc giả để tí tìm kiếm thông tin độc giả
			int bienThaoTac = 0;
			ShowCur(true);
			gotoxy(40, 30);
			cout << "NHAP TEN DOC GIA: ";
			bienThaoTac = nhap_ki_tu(tenDocGia, 0, 0, 8); // mã độc giả dạng string
			ShowCur(false);
			maDocGia = timKiemDocGiaTheoTen(arr, tenDocGia, index, dsDG, 2);
			if (bienThaoTac == -1)
				goto viTri;
		}
		if (thaoTacChucNang == F4)
		{
			nhapMa:
			string ma = "";
			int bienThaoTac = 0;
			ShowCur(true);
			gotoxy(40, 30);
			cout << "NHAP MA DOC GIA: ";
			bienThaoTac = nhap_ki_tu(ma, 2, 0, 7); // mã độc giả dạng string
			if (bienThaoTac == -1)
				goto viTri;
			if (ma.length() < 4 || ma.length() > 4)
			{
				inThongBao("MA DOC GIA CO 4 SO BROO!");
				Sleep(1000);
				xoaThongBao();
				gotoxy(57, 30);
				cout << "                                                                                                                                                                   ";
				goto nhapMa;
			}
			maDocGia = stringToNumber(ma);

			ShowCur(false);
			
			
		}
		if (thaoTacChucNang == ENTER)
		{
			maDocGia = arr[viTriDG]->docGia->data.mathe;
		}
		
			
			nodeDG = timKiemDocGiaTheoMa(dsDG, maDocGia);
			if (viewMuonTra == true)
			{
				if (nodeDG == NULL)
				{

					inThongBao("MA DOC GIA KHONG DUNG");
					Sleep(1000);
					xoaThongBao();
					gotoxy(57, 30);
					cout << "                                                                                                                                                                   ";
					goto nhapMa;
				}
				else
				{
				DC:
					// hiện số sách mà độc giả đang mượn
					system("cls");
					gotoxy(20, 5);
					cout << "CHE DO XEM";
					xuatSachMuon(nodeDG, l);
					gotoxy(20, 26);
					cout << "INS: MUON SACH -- DEL: TRA SACH -- HOME: MAT SACH";

					// dừng màn hinh chờ phím
					char phimThaoTac = _getch();
					if (phimThaoTac == -32) {
						phimThaoTac = _getch();
						if (phimThaoTac == INSERT) { // muon sach
							MUON_SACH(dsDG, l, nodeDG);
							ShowCur(false);
							ghiFileDanhSachDocGia(dsDG);
							ghiFileDS(l);
						}
						else if (phimThaoTac == DEL) { // tra sach
							traSach(nodeDG, l, true);
							ghiFileDanhSachDocGia(dsDG);
							ghiFileDS(l);
						}
						else if (phimThaoTac == HOME) {
							traSach(nodeDG, l, false);
							ghiFileDanhSachDocGia(dsDG);
							ghiFileDS(l);
						}

					}
					if (phimThaoTac == 27) {
						goto viTri;
					}

					goto DC;



				}
			}
			else { // xử lí quá hạn
				int i = 1;
				system("cls"); // xoá màn hình
				NormalLine();
				gotoxy(20, 20);
				cout << "NHAN ESC DE THOAT";
				gotoxy(20, 5);
				cout << "CHE DO XEM SACH QUA HAN ";
				gotoxy(45, 0);
				cout << "Ma Sach";
				gotoxy(60, 0);
				cout << "Ten Sach";
				gotoxy(100, 0);
				cout << "Ngay Muon";
				gotoxy(130, 0);
				cout << "Ngay Tra";
				gotoxy(160, 0);
				cout << "Trang Thai";
				for (PTR_MT p = nodeDG->data.mt.pHead; p != NULL; p = p->next) {
					if (p->data.trangthai == 0 && tinhSoNgay(p->data.ngaymuon) > 7)
					{
						string temp = tachMaSach(p->data.masach); // tách mã sách thành mã đầu sách 
						int index = timKiemDauSachTheoMa(l, temp); // return vị trí của đầu sách trong mảng
						ToMau(45, i, p->data.masach, false); // tô màu mã sách
						ToMau3(100, i, p->data.ngaymuon, false);// tô màu ngày
						ToMau3(130, i, p->data.ngaytra, false);// tô màu ngày
						ToMau(60, i, l.ds[index]->tensach, false); // to mau ten sACH
						ToMau(160, i, "DANG MUON", false);
						i++;
					}
				}
				while (true) {
					if (_getch() == 27)
						goto viTri;
				}
			}
		

	}

	
}

// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
void xoaMotDocGia(TREE_DG& dsDG, int maDocGia)
{
	if (dsDG != NULL)
	{
		// duyệt cây để tìm phần tử cần xóa
		if (dsDG->data.mathe < maDocGia)
		{
			xoaMotDocGia(dsDG->right, maDocGia);
		}
		else if (dsDG->data.mathe > maDocGia)
		{
			xoaMotDocGia(dsDG->left, maDocGia);
		}
		// đã tìm được mã độc giả
		else
		{
			int temp = demSoSachDocGiaDangMuon(dsDG);
			if (temp > 0)
			{
				inThongBao("DOC GIA DANG MUON SACH, VUI LONG TRA SACH TRUOC KHI XOA");
				Sleep(1000);
				xoaThongBao();
				return;
			}
			DOCGIA* nodeTheMang = dsDG;
			// xóa node có 1 con hoặc không có con nào
			if (dsDG->left == NULL) // cây con phải
			{
				dsDG = dsDG->right;
			}
			else if (dsDG->right == NULL) // cây con trái
			{
				dsDG = dsDG->left;
			}
			// xóa node có 2 con.Trái nhất của cây con phải
			else
			{
				// trái nhất của cây con phải
				timKiemPhanTuTheMang(nodeTheMang, dsDG->right);
			}
			delete nodeTheMang;
			inThongBao("XOA THANH CONG");
			Sleep(1000);
			xoaThongBao();
		}
	}
}


// TÌM PHÂN TỬ THẾ MẠNG TRONG CÂY NHỊ PHÂN TÌM KIẾM
void timKiemPhanTuTheMang(TREE_DG& canXoa, TREE_DG &theMang )
{
	// duyệt đến phần tử trái nhất của cây
	if (theMang->left != NULL)
	{
		timKiemPhanTuTheMang(canXoa, theMang->left);
	}
	// đã tìm được phần tử thế mạng
	else
	{
		canXoa->data = theMang->data;
		canXoa = theMang;
		theMang = theMang->right;
	}
}

// hóa đoán vị trí trong mảng con trỏ
void swapDocGia(DS_TAMTHOI* &tamThoi1, DS_TAMTHOI* &tamThoi2)
{
	DS_TAMTHOI* tamThoi;
	tamThoi = tamThoi1;
	tamThoi1 = tamThoi2;
	tamThoi2 = tamThoi;
	

}

void sapxep2(DS_TAMTHOI* arr[], int l, int r)
{
	string x, y;
	int i, j;
	i = l;
	j = r;
	x = arr[(l + r) / 2]->ten;
	y = arr[(l + r) / 2]->ho;
	do
	{
		while ((arr[i]->ten.compare(x) < 0) || (arr[i]->ten.compare(x) == 0 && arr[i]->ho.compare(y) < 0))i++;
		while ((arr[j]->ten.compare(x) > 0) || (arr[j]->ten.compare(x) == 0 && arr[j]->ho.compare(y) > 0))j--;
		if (i <= j)
		{
			swapDocGia(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j) sapxep2(arr, l, j);
	if (i < r) sapxep2(arr, i, r);
}

// sắp xếp độc giả theo tên + họ tăng dần
void sapXepTheoTen(DS_TAMTHOI* arr[], int slDG)
{
	/*
	for (int i = 0; i < slDG - 1; i++)
	{
		for (int j = i + 1; j < slDG; j++)
		{  // kiểm tra tên 2 đg
			if (arr[i]->ten.compare(arr[j]->ten) > 0)
			{
				// hoán đổi vị trí
				swapDocGia(arr[i], arr[j]);
			} // ngược lại
			else if (arr[i]->ten.compare(arr[j]->ten) == 0)
			{ // kiểm tra họ 2 đg
				if (arr[i]->ho.compare(arr[j]->ho) > 0)
				{ // hoán đổi vị trí
					swapDocGia(arr[i], arr[j]);
				}
			}
		}
	}
	*/
	sapxep2(arr, 0, slDG - 1);
}
// sắp xếp độc giả theo ngày quá hạn
void sapXepTheoNgayQuaHan(DS_TAMTHOI* arr[], int slDG)
{
	for (int i = 0; i < slDG - 1; i++)
	{
		for (int j = i + 1; j < slDG; j++)
		{  // kiểm tra tên 2 đg
			if (arr[i]->soNgayQuaHan < arr[j]->soNgayQuaHan)
			{
				// hoán đổi vị trí
				swapDocGia(arr[i], arr[j]);
			} // ngược lại
			
		}
	}
}


//2: của giao diện tìm kiếm độc giả ở quản lí mượn trả
//- enter : lấy mã độc giả
//1 : của giao diện tìm kiếm độc giả ở hiệu chỉnh độc giả
//- F2, 4, 5
// tìm kiếm độc giả theo tên
int timKiemDocGiaTheoTen(DS_TAMTHOI* arr[], string tuKhoa, int soLuongDG, TREE_DG dsDG, int statusGiaoDien)
{


	system("cls");
	ShowCur(false);
	
	
	DS_TAMTHOI* list[MAX_DS];
	int index = 0;
	int viTriDG = 0;

	int vitri_timthay ;
	bool KT; //biến vòng while nhỏ
	char signal; //biến bắt phím
	bool checkExist = false;
	
		for (int i = 0; i < soLuongDG; i++) //duyệt từ đầu đến cuối danh sách đầu sách
		{
			//tìm vị trí của chuỗi con tuKhoa trong tên độc giả
			vitri_timthay = arr[i]->ten.find(tuKhoa); 
			if (vitri_timthay != -1) //Nếu không được tìm thấy, nhận giá trị -1
			{
				/*xuatThongTinDocGia(arr[i]->docGia->data, thuTu++);*/
				list[index] = arr[i];
				index++;
				checkExist = true;
			}
		}
		if (checkExist == false)
		{
			inThongBao("DANH SACH RONG");
			Sleep(1000);
			xoaThongBao();
			return 0;
		}
		
		/*menuDocGiaTimKiem(list, index, viTriDG);*/
		if (statusGiaoDien == 1)
		{
			int thaoTacChucNang = menuDocGia(list, index, viTriDG, 3); 
			
			
			if (thaoTacChucNang == DEL) // xóa dg
			{
				xoaDocGia(dsDG, list[viTriDG]->docGia->data.mathe);
			}
			if (thaoTacChucNang == F2) // chỉnh sửa
			{
				hieuChinhDocGia(dsDG, list[viTriDG]->docGia->data.mathe);
			}
		}
		else {
			int thaoTacChucNang = menuDocGia(list, index, viTriDG, 4);

			if (thaoTacChucNang == ENTER)
			{

				return list[viTriDG]->docGia->data.mathe;
				
			}
		}

		return 0;

		
		

}
//1: menu ở giao diện độc giả 
//- F1 : tim kiem
//- INS : them
//- DEL : xoa
//- HOME : chinh sua
//2 : menu độc giả ở giao diện quản lí mượn trả
//- F1 : tìm kiếm
//- Enter : vào quản lí mượn trả
//3 : giao diện tìm kiếm ở giao diện độc giả
//- INS : them
//- DEL : xoa
//- HOME : chinh sua
//4 : giao diện tìm kiếm ở giao diện quản lí mượn trả
//Enter : vào quản lí mượn trả với mã số độc giả
void inMotTrangDG(DS_TAMTHOI* list[], int StartIndex, int soLuongDG, int statusGiaoDien)
{
	system("cls");
	NormalLine();
	
	if (statusGiaoDien == 1)
	{
		gotoxy(10, 20);
		cout << "F1: TIM KIEM";
		gotoxy(10, 21);
		cout << "INS: THEM";
		gotoxy(10, 22);
		cout << "DEL: XOA";
		gotoxy(10, 23);
		cout << "F2: HIEU CHINH";
		gotoxy(10, 24);
		cout << "ESC: THOAT";
		gotoxy(10, 25);
		cout << "Pg Up: TRANG KE TIEP --  Pg Dn: TRANG TRUOC";
	}else if (statusGiaoDien == 2)
	{
		gotoxy(10, 20);
		cout << "F1: TIM KIEM";
		gotoxy(10, 21);
		cout << "F4: TIM KIEM THEO MA";
		gotoxy(10, 22);
		cout << "ENTER: CHON";
		gotoxy(10, 23);
		cout << "ESC: THOAT";
		gotoxy(10, 24);
		cout << "Pg Up: TRANG KE TIEP --  Pg Dn: TRANG TRUOC";
	}
	else if (statusGiaoDien == 3)
	{
		gotoxy(10, 20);
		cout << "MENU TIM KIEM";
		gotoxy(10, 21);
		cout << "DEL: XOA";
		gotoxy(10, 22);
		cout << "F2: HIEU CHINH";
		gotoxy(10, 23);
		cout << "ESC: THOAT";
		gotoxy(10, 24);
		cout << "Pg Up: TRANG KE TIEP --  Pg Dn: TRANG TRUOC";
	}
	else {
		gotoxy(10, 21);
		cout << "ENTER: CHON";
		gotoxy(10, 22);
		cout << "ESC: THOAT";
		gotoxy(10, 23);
		cout << "Pg Up: TRANG KE TIEP --  Pg Dn: TRANG TRUOC";
	}

	
	int cs;
	for (int i = 0; i + StartIndex < soLuongDG && i < NumberPerPage; i++)
	{
		xuatThongTinDocGia(list[i + StartIndex]->docGia->data, i+1);
	}
}
//1: menu ở giao diện độc giả 
//- F1 : tim kiem
//- F2 : them
//- F4 : xoa
//- F5 : chinh sua
//2 : menu độc giả ở giao diện quản lí mượn trả
//- F1 : tìm kiếm
//- Enter : vào quản lí mượn trả
//3 : giao diện tìm kiếm ở giao diện độc giả
//- F2 : them
//- F4 : xoa
//- F5 : chinh sua
//4 : giao diện tìm kiếm ở giao diện quản lí mượn trả
//Enter : vào quản lí mượn trả với mã số độc giả
int menuDocGia(DS_TAMTHOI* list[], int soLuongDG, int &viTriDG, int statusGiaoDien)
{
	ShowCur(false);
	system("cls");
	
	trangDSHienTai = 1;
	soLuongTrangDS = (int)ceil((double)soLuongDG / NumberPerPage);
	inMotTrangDG(list, 0, soLuongDG, statusGiaoDien);
	gotoxy(X_Page + 30, Y_Page - 15);
	cout << " Trang " << trangDSHienTai << "/" << soLuongTrangDS;
	int chon = viTriDG % NumberPerPage;

	// tô màu dòng đầu tiên
	ToMau2(50, 1, list[viTriDG + chon]->docGia->data.mathe, true);

	int signal;
	while (true)
	{
		while (_kbhit)
		{
			signal = _getch();
			if (signal == ESC)
				return ESC;
			if (statusGiaoDien == 2 || statusGiaoDien == 4)
			{
				if (signal == ENTER)
				{
					viTriDG = chon + (trangDSHienTai - 1) * NumberPerPage;
					return ENTER;
				}
					
			}
			if (signal == 224)
			{
				signal = _getch();
				if (signal == PAGE_UP)
				{
					chon = 0;
					if (trangDSHienTai > 1)
						trangDSHienTai--;
					else trangDSHienTai = soLuongTrangDS;
					int viTri = (trangDSHienTai - 1) * NumberPerPage;
					inMotTrangDG(list, (trangDSHienTai - 1) * NumberPerPage, soLuongDG, statusGiaoDien);
					gotoxy(X_Page + 30, Y_Page - 15);
					cout << " Trang " << trangDSHienTai << "/" << soLuongTrangDS;
					ToMau2(50, chon + 1, list[viTri + chon]->docGia->data.mathe, true); // highligh phần dòng đầu tiên mỗi ô
				}
				else if (signal == PAGE_DOWN)
				{
					chon = 0;
					if (trangDSHienTai < soLuongTrangDS) trangDSHienTai++;							
					else trangDSHienTai = 1;
					inMotTrangDG(list, (trangDSHienTai - 1) * NumberPerPage, soLuongDG, statusGiaoDien);
					gotoxy(X_Page + 30, Y_Page - 15);
					cout << " Trang " << trangDSHienTai << "/" << soLuongTrangDS;
					int viTri = (trangDSHienTai - 1) * NumberPerPage;
					ToMau2(50, chon + 1, list[viTri + chon]->docGia->data.mathe, true);
				}

				else if (signal == UP && soLuongDG > 0)
				{
					
					if (chon > 0)
					{

						int viTri = (trangDSHienTai - 1) * NumberPerPage;
						ToMau2(50, chon + 1, list[viTri + chon]->docGia->data.mathe, false);
							chon--;
						ToMau2(50, chon + 1, list[viTri + chon]->docGia->data.mathe, true);
					}
					
				}
				else if (signal == DOWN)
				{
					if (chon < NumberPerPage - 1 && soLuongDG > 0)
					{
						int viTri = (trangDSHienTai - 1) * NumberPerPage;
						ToMau2(50, chon + 1, list[viTri + chon]->docGia->data.mathe, false);
						if((chon + viTri) < (soLuongDG -1))
						chon++;
						ToMau2(50, chon + 1, list[viTri + chon]->docGia->data.mathe, true);
					}
				}
				if (statusGiaoDien == 1 || statusGiaoDien == 3)
				{

					if (signal == DEL)  // xóa dg
					{
						viTriDG = chon + (trangDSHienTai - 1) * NumberPerPage;
						return DEL;

					}
					
				}
				
				if (statusGiaoDien == 1)
				{
					if (signal == INSERT)
					{
						return INSERT;
					}
				}
			}
			if (signal == 0)
			{
				signal = _getch();
				if (statusGiaoDien == 1 || statusGiaoDien == 2)
				{
					if (signal == F1)
					{
						return F1;
					}
				}
				
				if (statusGiaoDien == 1 || statusGiaoDien == 3)
				{

					if (signal == F2) // HIỆU CHỈNH
					{
						viTriDG = chon + (trangDSHienTai - 1) * NumberPerPage;
						return F2;
					}
				}
				if (statusGiaoDien == 2)
				{

					if (signal == F4) // HIỆU CHỈNH
					{
						return F4;
					}
				}
				
			}
		}

	}
}
void dieuChinhDocGia(TREE_DG &dsDG,  bool checkXepTheoTen)
{
reset:
	
	int viTriDG = 0;
	DS_TAMTHOI* arr[MAX_DS]; // khai bao mảng bằng số lượng độc giả
	
	int index = 0; // số lượng phần tử trong mảng
	duyetCay(dsDG, arr, index);
	int soLuongDG = SoluongDG(dsDG);
	if (checkXepTheoTen == true)
	{
		sapXepTheoTen(arr, soLuongDG);
	}
	
	int thaoTacChucNang = menuDocGia(arr, soLuongDG, viTriDG, 1);

	while (true)
	{
		
		if (thaoTacChucNang == ESC)
		{
			return;
		}
		if (thaoTacChucNang == F1)
		{
			string tenDocGia = "";  // mã độc giả để tí tìm kiếm thông tin độc giả
			int bienThaoTac = 0;
			ShowCur(true);
			gotoxy(40, 30);
			cout << "NHAP TEN DG: ";		
			bienThaoTac = nhap_ki_tu(tenDocGia, 0, 0, 3); // mã độc giả dạng string
			if (bienThaoTac == -1)
				goto reset;
			ShowCur(false);
			timKiemDocGiaTheoTen(arr, tenDocGia, index, dsDG, 1);
			goto reset;
		}
		if (thaoTacChucNang == INSERT)
		{
			while (true)
			{
				if (themDocGia(dsDG) < 0)
				{
					break;
				}
				
				index = 0;
				duyetCay(dsDG, arr, index);
				soLuongDG = SoluongDG(dsDG);
				if (checkXepTheoTen == true)
				{
					sapXepTheoTen(arr, soLuongDG);
				}
				inMotTrangDG(arr, (trangDSHienTai - 1) * NumberPerPage, soLuongDG, 1);
			}
			goto reset;
		}
		if (thaoTacChucNang == DEL) // xóa dg
		{
			xoaHuongDan();
			xoaDocGia(dsDG , arr[viTriDG]->docGia->data.mathe);
			goto reset;
		}
		if (thaoTacChucNang == F2) // chỉnh sửa
		{
			
			hieuChinhDocGia(dsDG, arr[viTriDG]->docGia->data.mathe);
			goto reset;
		}
		

	}
}
void xoaDocGia(TREE_DG &dsDG, int maDocGia)
{
	
		
	gotoxy(20, 20);
	cout << "DANG O CHE DO XOA DOC GIA -- NHAN ESC DE THOAT";
		
		if (xac_nhan(80, 40, "XAC NHAN XOA DOC GIA NAY ", "") == true)
		{
			ifstream filein("MADOCGIA.txt");
			ofstream filetemp("Temp.txt");
			DOCGIA* nodeDG = timKiemDocGiaTheoMa(dsDG, maDocGia);
			filetemp << nodeDG->data.mathe << endl;
			xoaMotDocGia(dsDG, maDocGia);
			
			int temp;
			while (filein >> temp)
			{
					filetemp << temp << endl;
			}
			filein.close();
			filetemp.close();
			if (remove("MADOCGIA.txt") < 0)
			{
				cout << "loi";
			}

			rename("Temp.txt", "MADOCGIA.txt");
			ghiFileDanhSachDocGia(dsDG);
		}
		

		
		
	
}

// hiệu chỉnh độc giả
int hieuChinhDocGia(TREE_DG &dsDG, int ma)
{

	xoaHuongDan();
	gotoxy(20, 20);
	cout << "DANG O CHE DO HIEU CHINH DOC GIA -- NHAN ESC DE THOAT";
	gotoxy(20, 21);
	cout << "<- -> : THAY DOI TRANG THAI";
	int i = nhapDSDG(dsDG, 2, ma);
	return i;
}

// HÀM NHẬP DI DUYỂN LÊN XUỐNG
int nhapDSDG(TREE_DG& dsDG, int flag, int ma)
{
	int viTri = 0;// so thu tu bat dau nhap
	int kt;
	int khoangCach = 8;
	int checkGioiTinh = 0;
	char c = ' ';
	ifstream filein("MADOCGIA.txt");
	ofstream filetemp("Temp.txt");
	
	docgia docgia; // độc giả để nhận giá trị nhập từ bàn phím

	DOCGIA* nodeDocGia = new DOCGIA;
	nodeDocGia->left = nodeDocGia->right = NULL;

	ShowCur(true);

	

	while (true)
	{
		switch (viTri)
		{
		case 0:
		{
			if (flag == 0) //trường hợp nhập mới
			{				
				filein >> docgia.mathe;
				docgia.trangthaithe = 1;
				hienThongTin1DG(docgia);
			}

			if (flag == 2) //chỉnh sửa
			{
				
				nodeDocGia = timKiemDocGiaTheoMa(dsDG, ma);
				docgia = nodeDocGia->data;
				hienThongTin1DG(docgia);
				
			}
			viTri++;
			break;
		}
		case 1:
		{
			xoaThongBao();
			ShowCur(true);
			NormalLine();
			kt = nhap_ki_tu(docgia.ho, 0, viTri + 1, khoangCach);
			if (kt == -1)//ESC
			{
				filein.close();
				filetemp.close();
				return -1;
			}
			if (kt == KEY_UP)
			{
				
				break;
			}
			else
			{
				viTri++;
				break;
			}
		}
		case 2:
		{
			xoaThongBao();
			ShowCur(true);
			NormalLine();
			kt = nhap_ki_tu(docgia.ten, 0, viTri + 1, khoangCach);
			if (kt == -1)
			{
				filein.close();
				filetemp.close();
				return -1;
			}
			if (kt == KEY_UP)
			{

				viTri--;
				break;
			}
			viTri++;
			break;
		}
		case 3:
		{
			xoaThongBao();
			checkGioiTinh = gioiTinh(X_Add , 38, docgia.phai);
			if (checkGioiTinh == 1) {
				docgia.phai = "NAM";
			}
			else if (checkGioiTinh == 2) {
				docgia.phai = "NU";
			}
			if (checkGioiTinh == KEY_UP)
			{

				viTri--;
				break;
			}
			if (checkGioiTinh == -1) {
				return -1;
			}
			viTri++;
			break;
			
		}
		case 4:
		{
			xoaThongBao();
			if (flag == 0)
			{
				if (checkGioiTinh > 0)
				{
					viTri++;
					checkGioiTinh = 0;
					break;

				}else if (c == KEY_UP)
				{
					viTri--;
					break;
				}
				
			}
			else {
				int checkTrangThai = trangThaiDocGia(X_Add + khoangCach + 4, 40, docgia.trangthaithe);
				if (checkTrangThai == 1) {
					docgia.trangthaithe = 1;
				}
				else if (checkTrangThai == 0) {
					docgia.trangthaithe = 0;
				}
				if (checkTrangThai == -1) {
					NormalLine();
					return -1;
				}
				if (checkTrangThai == KEY_UP)
				{

					viTri--;
					break;
				}
				viTri++;
				break;
			}
			
			
		}
		case 5:
		{
			xoaThongBao();
			gotoxy(X_Add + khoangCach,  42);
			HighlightLine();
			cout << "ENTER";
			nhanEnter:
			c = _getch();
			if (c == -32) c = _getch();
			if (c == 27)
			{
				filein.close();
				filetemp.close();
				return -1;
			}else
			if (c == KEY_UP)
			{
				gotoxy(X_Add + khoangCach, 42);
				NormalLine();
				cout << "ENTER";
				viTri--;
				break;
			}else

			if (c == ENTER)
			{
				nodeDocGia->data = docgia;
				if (flag == 0) //trường hợp nhập mới
				{
					// khởi tạo nocde độc giả
					if (checkGioiTinh == 0) {
						nodeDocGia->data.phai = "NAM";
					}
					khoiTaoMuonTra(nodeDocGia->data.mt);
					themDG(dsDG, nodeDocGia);
					int temp;
					while (filein >> temp)
					{
						if (temp != docgia.mathe)
							filetemp << temp << endl;
					}
					filein.close();
					filetemp.close();
					if (remove("MADOCGIA.txt") < 0)
					{
						cout << "loi";
					}
					
					rename("Temp.txt", "MADOCGIA.txt");
					inThongBao("THEM THANH CONG");
					Sleep(1000);
					xoaThongBao();
				
				}
				if (flag == 2) //trường hợp chỉnh sửa
				{
					
					inThongBao("CHINH SUA THANH CONG");
					Sleep(1000);
					xoaThongBao();
				}
				ghiFileDanhSachDocGia(dsDG);
				NormalLine();
				return 0;
			}
			else
			{
				goto nhanEnter;
			}


		}
		}
	}
	
}
// hiện  thông tin độc giả
void hienThongTin1DG(docgia docgia)
{

	int khoangCach = 8;
	
	gotoxy(X_Add, Y_Add + 2);
	cout << "MA THE: ";
	gotoxy(X_Add + khoangCach + 2, Y_Add + 2);
	cout << docgia.mathe;
	gotoxy(X_Add, Y_Add + 4);
	cout << "HO: ";
	gotoxy(X_Add + khoangCach, Y_Add + 4);
	cout << docgia.ho;
	gotoxy(X_Add, Y_Add + 6);
	cout << "TEN: ";
	gotoxy(X_Add + khoangCach, Y_Add + 6);
	cout << docgia.ten;
	gotoxy(X_Add, Y_Add + 8);
	cout << "GIOI TINH: ";
	gotoxy(X_Add + 15, Y_Add + 8);
	cout << "NAM ";
	gotoxy(X_Add + 20, Y_Add + 8);
	cout << "NU ";
	gotoxy(X_Add, Y_Add + 10);
	cout << "TINH TRANG: ";
	gotoxy(X_Add + khoangCach + 4, Y_Add + 10);
	if (docgia.trangthaithe == 1)
		cout << "HOAT DONG";
	else
		cout << "KHOA";
	gotoxy(X_Add + khoangCach, Y_Add + 12);
	cout << "ENTER";
}
// xóa  thông tin độc giả
void xoaThongTin1DG()
{

	int khoangCach = 8;

	gotoxy(X_Add + khoangCach + 2, Y_Add + 2);
	cout << "                                                                           ";
	gotoxy(X_Add + khoangCach, Y_Add + 4);
	cout << "                                                                           ";
	gotoxy(X_Add + khoangCach, Y_Add + 6);
	cout << "                                                                           ";

}
// xóa hướng dẫn
void xoaHuongDan()
{
	gotoxy(10, 20);
	cout << "                 ";
	gotoxy(10, 21);
	cout << "                ";
	gotoxy(10, 22);
	cout << "              ";
	gotoxy(10, 23);
	cout << "                ";
	gotoxy(10, 24);
	cout << "                                                          ";
	gotoxy(10, 25);
	cout << "                                                 ";
}
// lựa chọn giới tính
int trangThaiDocGia(int x, int y, int trangThaiHienTai)
{
	ShowCur(false);
	char c;
	// hiện khung xác nhận trả sach
	if (trangThaiHienTai == 0)
		goto KHOA;
	

	while (1)
	{
		// hiện thị đang ở lưa chọn có
		/*gotoxy(x + 15, y ); SetColor(252); cout << "NAM";
		gotoxy(x + 20, y); SetColor(247); cout << "NU";*/
		
		ToMau(x , y, "HOAT DONG", TRUE);

		c = _getch();
		// nếu nhấn enter thì trả về true để xóa
		if (c == 13) {

			return 1;
		}
		else if (c == 27)
		{

			return -1;
		}
		if (c == -32) c = _getch();
		if (c == 77 || c == 75)
		{
			KHOA:
			// nhấn di chuyển thì chuyển qua hủy ( nếu tiếp tục di chuyển thì quay về vòng lặp)
			/*gotoxy(x + 15, y ); SetColor(247); cout << "NAM";
			gotoxy(x + 20, y ); SetColor(252); cout << "NU";*/
			gotoxy(x, y);
			cout << "                    ";
			ToMau(x , y, "KHOA", true);
			c = _getch(); if (c == 0 || c == -32) c = _getch();
			if (c == 13) {
				return 0;
			}
			else if (c == 27) {
				return -1;
			}
			else if (c == UP)
			{
				return UP;
			}
			else if (c == DOWN)
			{
				return DOWN;
			}
		}
		else if (c == UP || c == DOWN) {
			if (c == UP)
			{
				return UP;
			}
			else if (c == DOWN)
			{
				return DOWN;
			}
		}
	}
}
// ===========================================     QUEUE
// hàm khởi tạo queue
void KhoiTaoQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

// hàm khởi tạo 1 cái DATA
DATA* KhoiTaoNodeQueue(TREE_DG x)
{
	DATA* p = new DATA();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->giaTri = x; // thêm giá trị của biến x vào trong data của cái DATA
	p->pNext = NULL;
	return p;
}

// =============== KIỂM TRA QUEUE CÓ RỖNG HAY KHÔNG ===============
bool IsEmpty(QUEUE q)
{
	// nếu danh sách rỗng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

// =============== THÊM 1 PHẦN TỬ VÀO CUỐI QUEUE- FIFO ===============
bool Push(QUEUE& q, DATA* p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // DATA p chính là DATA đầu và DATA cuối
	}
	else // danh sách đã có phần tử
	{
		q.pTail->pNext = p; // liên kết con trỏ cuối của danh sách với phần tử p cần thêm vào
		q.pTail = p; // cập nhật lại con trỏ cuối là DATA p
	}
	return true;
}

// =============== LẤY PHẦN TỬ ĐẦU QUEUE VÀ HỦY NÓ ĐI - FIFO ===============
bool Pop(QUEUE& q, TREE_DG& x) // x chính là giá trị cần lấy trong DATA
{
	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		DATA* p = q.pHead; // DATA p chính là DATA thế mạng để tí nữa chúng ta xóa nó đi
		x = p->giaTri; // gán giá trị của DATA đầu stack vào biến x	
		q.pHead = q.pHead->pNext; // cập nhật DATA đầu queue là DATA tiếp theo	
		delete p; // xóa DATA đầu queue vừa lấy 

	}
	return true;// lấy phần tử đầu queue thành công
}

// ===========================================   END  QUEUE
/*
cách sử dụng: biến check mặc định là false
nếu hàm chạy xong check vẫn bằng flase thì sách chưa từng có người mượn
còn nếu bị gán là true thì đã bị mượn và dừng trường trình
*/
void checkSachDaTungMuon(TREE_DG dsDG, string maSach, bool &check)
{
	if (dsDG != NULL)
	{
		checkSachDaTungMuon(dsDG->left, maSach, check); // CHẠY SANG BÊN TRÁI TRƯỚC
		if (kiemTraSachDangDaMuonCuaMotDocGia(dsDG, maSach) == true) // node
		{
			check = true;
			return;
		}
		checkSachDaTungMuon(dsDG->right, maSach, check); // chạy sang phải 
	}// nếu cây rỗng thoát hàm
	else return;
	
}
// hàm kiểm tra sách này đã từng bị độc giả này mượn hay chưa <> rt true nếu đã từng mượn
bool kiemTraSachDangDaMuonCuaMotDocGia(TREE_DG p, string ma_sach)
{
	/*string s = tachMaSach(ma_sach);
	string temp;*/
	for (PTR_MT q = p->data.mt.pHead; q != NULL; q = q->next)
	{		
			//temp = tachMaSach(q->data.masach);
			//if (temp == s) // đang mượn cuốn sách có đầu sách tương tự
		if(q->data.masach.compare(ma_sach) == 0)
				return true;		
	}
	return false;
}

// XOA XAC NHAN
void xoaXacNhan()
{
	gotoxy(80 , 15 ); SetColor(252); cout << "                                                            ";
	gotoxy(80 + 25, 15 + 2); SetColor(252); cout << "                           ";
	gotoxy(80 + 30, 15 + 2); SetColor(247); cout << "                           ";
}

// -------------- duyệt cây theo LNR và đưa vào mảng
void duyetCayQuaHan(TREE_DG ds_docGia, DS_TAMTHOI* nodes[], int& n)
{
	if (ds_docGia != NULL)
	{
		duyetCayQuaHan(ds_docGia->left, nodes, n);
		

		int dem = 0;
		for (PTR_MT q = ds_docGia->data.mt.pHead; q != NULL; q = q->next) // duyệt từ danh sách mượn trả và kiếm sách có số ngày mượn cao nhất
		{
			if (q->data.trangthai == 0) // dang muon sach
			{
				if (tinhSoNgay(q->data.ngaymuon) > dem)
				{
					dem = tinhSoNgay(q->data.ngaymuon);
				}
			}
		}
		if (dem > 7) { // nếu số ngày mượn lớn hơn 7 thì mới cho vào danh sách mảng tạm
			nodes[n] = new DS_TAMTHOI;
			nodes[n]->docGia = ds_docGia;
			nodes[n]->ten = ds_docGia->data.ten;
			nodes[n]->soNgayQuaHan = dem;
			n++;
		}
			
		duyetCayQuaHan(ds_docGia->right, nodes, n);
	}
}

void menuXemDanhMucSach(LIST_DS l, string isbn, PTR_DMS& First, int& slsach, TREE_DG dsDG)
{
	huongDan1();
	int signal;
	quay_lai:
	veXoaBang1(cotDMS, 4, false);
	gotoxy(xKeyDisplay1[0], 2);
	cout << " So luong sach : " << slsach << "    ";
	while (slsach == 0)
	{
		signal = _getch();
		if (signal == ESC)
			return;
		if (signal == 224)
		{
			signal = _getch();
			if (signal == INSERT)
			{
				taoBangNhap("Nhap moi sach", thongTinDMS, 0, 4, 50);
				slsach = nhapDMS(l, isbn, First);
				ShowCur(false);
			}
		}
	}
	trangDMSHienTai = 1;
	soLuongTrangDMS = (int)ceil((double)slsach / NumberPerPageDMS);
	PTR_DMS nodes[MAX_DMS];
	luuChiSoCuaDMS(First, nodes);
	veXoaBang1(cotDMS, 4, true);	
	inMotTrangDMS(nodes, 0, slsach);
	int kt = 0;
	string masach = "";
	bool check = false; //biến kiểm tra xem sách đã từng được mượn hay chưa

	int thanhSang = 0; //thanh sáng để chọn sách
	int chiSoBatDau = (trangDMSHienTai - 1) * NumberPerPageDMS;
	int cs = thanhSang + chiSoBatDau;

	while (true)
	{
		//tô màu dòng được chọn
		HighlightLine();
		inMotDMS(nodes[cs], thanhSang, chiSoBatDau);
		NormalLine();
		//====================
		signal = _getch();
		if (signal == ESC)
			return;
		if (signal == 224)
		{
			signal = _getch();
			if (signal == PAGE_UP)
			{
				if (trangDMSHienTai > 1)
					trangDMSHienTai--;
				else trangDMSHienTai = soLuongTrangDMS;
				chiSoBatDau = (trangDMSHienTai - 1) * NumberPerPageDMS;
				thanhSang = 0;
				cs = thanhSang + chiSoBatDau;
				inMotTrangDMS(nodes, chiSoBatDau, slsach);
			}
			else if (signal == PAGE_DOWN)
			{
				if (trangDMSHienTai < soLuongTrangDMS)
					trangDMSHienTai++;
				else trangDMSHienTai = 1;
				chiSoBatDau = (trangDMSHienTai - 1) * NumberPerPageDMS;
				thanhSang = 0;
				cs = thanhSang + chiSoBatDau;
				inMotTrangDMS(nodes, chiSoBatDau, slsach);
			}
			if (signal == KEY_UP)
			{
				if (thanhSang > 0)
				{
					NormalLine();
					inMotDMS(nodes[cs], thanhSang, chiSoBatDau);
					thanhSang--;
					cs = thanhSang + chiSoBatDau;

				}
			}
			else if (signal == KEY_DOWN)
			{
				if ((thanhSang < NumberPerPage - 1) && (thanhSang + chiSoBatDau < slsach - 1))
				{
					NormalLine();
					inMotDMS(nodes[cs], thanhSang, chiSoBatDau);
					thanhSang++;
					cs = thanhSang + chiSoBatDau;
				}
			}
			else if (signal == INSERT)
			{
				taoBangNhap("Nhap moi sach", thongTinDMS, 0, 4, 50);
				kt = nhapDMS(l, isbn, First);
				ShowCur(false);
				if (kt != 0)
				{
					slsach += kt;
					luuChiSoCuaDMS(First, nodes);
					soLuongTrangDMS = (int)ceil((double)slsach / NumberPerPageDMS);
					inMotTrangDMS(nodes, chiSoBatDau, slsach);
				}
			}
			else if (signal == DEL)
			{				
				masach = nodes[cs]->data.masach;
				checkSachDaTungMuon(dsDG, masach, check);
				if (check == true)
				{
					inThongBao("Sach da tung duoc muon!");
					check = false;
				}					
				else
				{
					int luaChon = menu_xoa(X_Notification, Y_Notification + 1);
					if (luaChon == 0) // Có
					{
						xoaDMSTheoMa(First, masach);
						slsach--;
						inThongBao("Xoa thanh cong!");
						ghiFileDS(l);
						if (slsach == 0)
							goto quay_lai;
						else
						{
							chiSoBatDau = 0;
							luuChiSoCuaDMS(First, nodes);
							soLuongTrangDMS = (int)ceil((double)slsach / NumberPerPageDMS);
							inMotTrangDMS(nodes, chiSoBatDau, slsach);
							trangDMSHienTai = 1;
							thanhSang = 0;
							cs = thanhSang + chiSoBatDau;
						}						
					}
				}
			}
		}
		if (signal == 0)
		{
			signal = _getch();
			if (signal == KEY_F2) //Chỉnh sửa sách
			{
				taoBangNhap("Chinh sua thong tin sach", cotDMS, 1, 4, 50);
				kt = suaDMS(nodes[cs]);
				if (kt == 1)
				{
					inMotTrangDMS(nodes, chiSoBatDau, slsach);
					ghiFileDS(l);
				}				
				ShowCur(false);
			}
		}
	}
}

//Trả về số lượng đầu sách tìm được, flag = 0: in sách để xem, xóa, sửa; flag = 1: in sách để mượn
int timKiemDSTheoTen(LIST_DS& l, string tuKhoa, int flag, string& masach, int& ktxoasua, int& slDSThem, TREE_DG dsDG)
{
	ShowCur(false);
	int* a = new int[l.n]; //mảng lưu chỉ số đầu sách được tìm thấy
	int dem; //biến lưu số lượng đầu sách được tìm thấy
	int vitri_timthay;
	int kt; //biến kiểm tra giá trị trả về
	char signal; //biến bắt phím
	int pointer; //biến thanh sáng đầu sách
	int slsach = 0; //biến lưu số lượng sách của đầu sách được chọn
	int chiSoBatDau;
	int cs;

timKiem:
	pointer = 0;
	dem = 0;
	for (int i = 0; i < l.n; i++) //duyệt từ đầu đến cuối danh sách đầu sách để tìm
	{
		//tìm vị trí của chuỗi con tuKhoa trong tên đầu sách
		vitri_timthay = l.ds[i]->tensach.find(tuKhoa);
		if (vitri_timthay != -1) //Nếu không được tìm thấy, nhận giá trị -1
		{
			a[dem] = i; //lưu lại vị trí đầu sách này
			dem++;
		}
	}

	if (dem == 0) //không tìm thấy đầu sách thích hợp
	{
		delete[] a;
		return dem;
	}

	//nếu tìm thấy
	//system("cls");
	xoaNoiDungBiDu(0, 7);
	trangDSTimKiemHienTai = 1;
	// ceil lam tron len
	soLuongTrangDSTimKiem = (int)ceil((double)dem / NumberPerPage1);
	inMotTrangDSTimKiem(l, a, dem, 0);
	veBang(thongTinDS, 7);
	chiSoBatDau = (trangDSTimKiemHienTai - 1) * NumberPerPage1;
	cs = a[pointer + chiSoBatDau];

	while (true)
	{
		//tô màu dòng đầu tiên
		HighlightLine();
		inMotDS(l.ds[cs], pointer, chiSoBatDau);
		NormalLine();
		//=========================
		signal = _getch();// kiem tra xem co nhap gi tu ban phim khong
		if (signal == ESC)
		{
			delete[] a;
			xoaBangNhap();
			return dem;
		}
		else if (signal == -32)
		{
			signal = _getch();

		}
		else if (signal == 0)
		{
			signal = _getch();
		}
		// dieu huong
		switch (signal)
		{
		case PAGE_UP:
			if (trangDSTimKiemHienTai > 1)
				trangDSTimKiemHienTai--;
			else trangDSTimKiemHienTai = soLuongTrangDSTimKiem;
			chiSoBatDau = (trangDSTimKiemHienTai - 1) * NumberPerPage1;
			inMotTrangDSTimKiem(l, a, dem, chiSoBatDau);
			pointer = 0;
			cs = a[pointer + chiSoBatDau];

			break;
		case PAGE_DOWN:
			if (trangDSTimKiemHienTai < soLuongTrangDSTimKiem)
				trangDSTimKiemHienTai++;
			else trangDSTimKiemHienTai = 1;
			chiSoBatDau = (trangDSTimKiemHienTai - 1) * NumberPerPage1;
			inMotTrangDSTimKiem(l, a, dem, chiSoBatDau);
			pointer = 0;
			cs = a[pointer + chiSoBatDau];
			break;
		case KEY_UP:
			if (pointer > 0)
			{
				NormalLine();
				inMotDS(l.ds[cs], pointer, chiSoBatDau);
				pointer--;
				cs = a[pointer + chiSoBatDau];
			}
			break;
		case KEY_DOWN:
			if ((pointer < NumberPerPage1 - 1) && (pointer + chiSoBatDau < dem - 1))
			{
				NormalLine();
				inMotDS(l.ds[cs], pointer, chiSoBatDau);
				pointer++;
				cs = a[pointer + chiSoBatDau];
			}
			break;
		case INSERT:
			if (flag == 0)
			{
				if (l.n == MAX)
				{
					inThongBao("Danh sach day, khong the them");
					break;
				}
				if (slDSThem == 20)
				{
					inThongBao("Da them sach 20 lan, hay ve trang chu de reset lai so lan");
					break;
				}
				taoBangNhap("Nhap moi dau sach", thongTinDS, 1, 7, 50);
				kt = nhapDS(l, cs, 0);
				if (kt == 1)
				{
					slDSThem++;
					ktxoasua++;
					ghiFileDS(l);
					goto timKiem;
				}
			}
			break;
		case DEL:
			if (flag == 0)
			{
				kt = nhapDS(l, cs, 1);
				if (kt == 1)
				{
					ktxoasua++;
					ghiFileDS(l);
					if (dem > 1)
						goto timKiem;
					return dem;
				}
			}
			break;
		case KEY_F2:
			if (flag == 0)
			{
				taoBangNhap("Chinh sua thong tin dau sach", thongTinDS, 1, 7, 50);
				kt = nhapDS(l, cs, 2);
				if (kt == 1)
				{
					ktxoasua++;
					ghiFileDS(l);
					goto timKiem;
				}
			}
			break;
		case ENTER:// chọn đầu sách để xem sách			
			slsach = demSoLuongSach(*l.ds[cs]);			
			
			if (flag == 0)
			{
				system("cls");
				gotoxy(X_TitlePage, Y_TitlePage);
				cout << l.ds[cs]->ISBN << " - " << l.ds[cs]->tensach << "\n\n";
				menuXemDanhMucSach(l, l.ds[cs]->ISBN, l.ds[cs]->dms, slsach, dsDG);
				system("cls");
				//xoa(39, 0, 128, 40);
				inMotTrangDSTimKiem(l, a, dem, chiSoBatDau);
				veBang(thongTinDS, 7);
				huongDan();
				break;
			}
			else
			{				
				xoa(39, 0, 128, 29);
				gotoxy(X_TitlePage, Y_TitlePage);
				cout << l.ds[cs]->ISBN << " - " << l.ds[cs]->tensach << "\n\n";
				masach = menuChonDanhMucSach(l.ds[cs]->dms, slsach);
				xoa(39, 0, 128, 29);
				return dem;
			}
			
		}
	}
}

void menuDauSach(LIST_DS& l, TREE_DG dsDG)
{
	ShowCur(false);
	//system("cls");
	listTheLoai listTL;
	listTL.nodes = new indexTheLoai[l.n + 20];
	sapXepGiuNguyenIndex(l, listTL);
	int slDSThem = 0; //biến đếm số lượng đầu sách đã thêm

	trangDSHienTai = 1;
	// ceil lam tron len
	soLuongTrangDS = (int)ceil((double)l.n / NumberPerPage);
	inMotTrangDS(l, listTL, 0);
	veBang(thongTinDS, 7);
	huongDan();
	string tuKhoa = ""; //biến để tìm kiếm sách
	int kt; //biến kiểm tra giá trị trả về
	string masach;
	int sldausach; //số lượng đầu sách tìm được
	int slsach; //số lượng sách của đầu sách được chọn
	int signal; //biến bắt phím
	int thanhSang = 0; //thanh sáng để chọn đầu sách
	int chiSoBatDau = (trangDSHienTai - 1) * NumberPerPage;
	int cs = listTL.nodes[thanhSang + chiSoBatDau].chiso; //index của đầu sách đang được chọn
	int ktxoasua;
	while (true)
	{
		//tô màu dòng được chọn
		HighlightLine();
		inMotDS(l.ds[cs], thanhSang, chiSoBatDau);
		NormalLine();
		//====================
		signal = _getch();
		if (signal == ENTER)
		{
			slsach = demSoLuongSach(*l.ds[cs]);
			system("cls");
			//xoa(39, 0, 128, 40);
			gotoxy(X_TitlePage, Y_TitlePage);
			cout << l.ds[cs]->ISBN << " - " << l.ds[cs]->tensach << "\n\n";
			menuXemDanhMucSach(l, l.ds[cs]->ISBN, l.ds[cs]->dms, slsach, dsDG);
			system("cls");
			//xoa(39, 0, 128, 40);
			inMotTrangDS(l, listTL, chiSoBatDau);
			veBang(thongTinDS, 7);
			huongDan();
		}
		if (signal == ESC)
		{
			delete[] listTL.nodes;
			return;
		}
		if (signal == 224)
		{
			signal = _getch();
			if (signal == PAGE_UP)
			{
				if (trangDSHienTai > 1)
					trangDSHienTai--;
				else trangDSHienTai = soLuongTrangDS;
				chiSoBatDau = (trangDSHienTai - 1) * NumberPerPage;
				inMotTrangDS(l, listTL, chiSoBatDau);
				thanhSang = 0;
				cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;

			}
			else if (signal == PAGE_DOWN)
			{
				if (trangDSHienTai < soLuongTrangDS)
					trangDSHienTai++;
				else trangDSHienTai = 1;
				chiSoBatDau = (trangDSHienTai - 1) * NumberPerPage;
				inMotTrangDS(l, listTL, chiSoBatDau);
				thanhSang = 0;
				cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;

			}
			if (signal == KEY_UP)
			{
				if (thanhSang > 0)
				{
					NormalLine();
					inMotDS(l.ds[cs], thanhSang, chiSoBatDau);
					thanhSang--;
					cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;

				}

			}
			else if (signal == KEY_DOWN)
			{
				if ((thanhSang < NumberPerPage - 1) && (thanhSang + chiSoBatDau < l.n - 1))
				{
					NormalLine();
					inMotDS(l.ds[cs], thanhSang, chiSoBatDau);
					thanhSang++;
					cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;

				}
			}
			// them moi
			else if (signal == INSERT) //Thêm đầu sách
			{
				if (l.n == MAX)
				{
					inThongBao("Danh sach day, khong the them");
					continue;
				}
				if (slDSThem == 20)
				{
					inThongBao("Da them sach 20 lan, hay ve trang chu de reset lai so lan");
					continue;
				}
				taoBangNhap("Nhap moi dau sach", thongTinDS, 1, 7, 50);
				kt = nhapDS(l, cs, 0);
				if (kt == 1)
				{
					sapXepGiuNguyenIndex(l, listTL);
					inMotTrangDS(l, listTL, chiSoBatDau);
					cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;
					slDSThem++;
				}
				ShowCur(false);
			}// endif signal == INSERT

			// xoa di
			else if (signal == DEL) //Xóa đầu sách
			{
				if (l.n == 0)
				{
					inThongBao("Danh sach rong");
					continue;
				}

				kt = nhapDS(l, cs, 1);
				if (kt == 1)
				{
					chiSoBatDau = 0;
					trangDSHienTai = 1;
					sapXepGiuNguyenIndex(l, listTL);
					inMotTrangDS(l, listTL, chiSoBatDau);
					thanhSang = 0;
					cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;
				}

				ShowCur(false);
			}//else if( signal == DEL)

		}
		if (signal == 0)
		{
			signal = _getch();
			if (signal == KEY_F2)
			{
				taoBangNhap("Chinh sua thong tin dau sach", thongTinDS, 1, 7, 50);
				kt = nhapDS(l, cs, 2);
				if (kt == 1)
				{
					sapXepGiuNguyenIndex(l, listTL);
					inMotTrangDS(l, listTL, chiSoBatDau);
					cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;
				}

				ShowCur(false);
			}
			else if (signal == KEY_F1)
			{
				ktxoasua = 0;
				//system("cls");
				taoBangNhap("Tim sach theo ten", thongTinDS, 2, 3, 50);

				ShowCur(true);
				kt = nhap_ki_tu(tuKhoa, 1, 0, 15);
				if (kt == -1) //ESC
				{
					xoaBangNhap();
					xoaThongBao();
					continue;
				}
				sldausach = timKiemDSTheoTen(l, tuKhoa, 0, masach, ktxoasua, slDSThem, dsDG);

				if (sldausach == 0)
				{
					xoaThongBao();
					inThongBao("Khong tim thay dau sach thich hop!");
					xoaBangNhap();
					continue;
				}
				if (ktxoasua != 0)
				{
					sapXepGiuNguyenIndex(l, listTL);
					cs = listTL.nodes[thanhSang + chiSoBatDau].chiso;
				}
				gotoxy(1, 2);
				cout << setw(40) << setfill(' ') << "";
				NormalLine();
				inMotTrangDS(l, listTL, chiSoBatDau);
				veBang(thongTinDS, 7);
				huongDan();

				ShowCur(false);
			}
		}
	}// while(true)
}

void giaiphong_cay(TREE_DG& dsDG)
{
	if (dsDG != NULL)
	{
		PTR_MT p = NULL;
		while (dsDG->data.mt.pHead != NULL)
		{
			p = dsDG->data.mt.pHead;
			dsDG->data.mt.pHead = dsDG->data.mt.pHead->next;
			delete p;
		}
		giaiphong_cay(dsDG->left);
		giaiphong_cay(dsDG->right);
		delete dsDG;
		dsDG = NULL;
	}
}