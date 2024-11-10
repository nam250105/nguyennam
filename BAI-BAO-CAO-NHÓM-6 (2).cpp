    #include <iostream>
	#include <string>
	#include <iomanip>
	#include <algorithm>
	#include <cctype> 
	#include <limits>
	using namespace std;

	bool kiemtraten(const string& ten) {
    if (ten.empty()) {
        return false;
    }
    for (char c : ten) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

	
	struct SanPham {
	    int id;
	    string ten;
	    double gia;
	    int soLuong;
	};
	
	bool kiemTraSoLuong(int soLuong) {
		 return soLuong > 0;
	}
	void nhapSoLuong(int& soLuong) {
		while (true) {
	        cout << "Nhap so luong san pham (so nguyen duong): ";
	        cin >> soLuong;
	        if (cin.fail() || !kiemTraSoLuong(soLuong)) {
	            cin.clear();
	            cout << "Nhap sai! So luong phai la mot so nguyen duong. Vui long nhap lai." << endl;
	            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	        } else {
	            break;
	        }
	    
		}
	};
	
	struct KhachHang {
	    int id;
	    string ten;
	    string dienThoai;
	    string email;
	};
	
	struct NodeSanPham {
	    SanPham data;
	    NodeSanPham* next;
	};
	
	struct NodeKhachHang {
	    KhachHang data;
	    NodeKhachHang* next;
	};
	
	struct DanhSachKhachHang {
	    NodeKhachHang* head;
	
	    DanhSachKhachHang() {
	        head = nullptr;
	    }
	  
	    
	    
	    bool kiemTraSoLuong(int soLuong) {
	    return soLuong > 0;
		}
	    
	    
	
	    void themKhachHang(KhachHang khachHang) {
	        NodeKhachHang* newNode = new NodeKhachHang{khachHang, nullptr};
	        if (!head) {
	            head = newNode;
	        } else {
	            NodeKhachHang* current = head;
	            while (current->next) {
	                current = current->next;
	            }
	            current->next = newNode;
	        }
	    }
	
	
	
	    KhachHang* timKhachHangTheoId(int id) {
	        NodeKhachHang* current = head;
	        while (current) {
	            if (current->data.id == id) {
	                return &current->data;
	            }
	            current = current->next;
	        }
	        return nullptr;
	    }
	
	    void hienThiKhachHang() {
	        if (!head) {
	            cout << "Danh sach khach hang trong!" << endl;
	            return;
	        }
	        NodeKhachHang* current = head;
	        while (current) {
	            cout << "ID: " << current->data.id << " | Ten: " << current->data.ten
	                 << " | Dien thoai: " << current->data.dienThoai << " | Email: " << current->data.email << endl;
	            current = current->next;
	        }
	    }
	
	    void xoaKhachHang(int id) {
	        if (!head) {
	            cout << "Danh sach khach hang trong!" << endl;
	            return;
	        }
	        if (head->data.id == id) {
	            NodeKhachHang* temp = head;
	            head = head->next;
	            delete temp;
	            cout << "Xoa khach hang thanh cong!" << endl;
	            return;
	        }
	        NodeKhachHang* current = head;
	        while (current->next && current->next->data.id != id) {
	            current = current->next;
	        }
	        if (current->next) {
	            NodeKhachHang* temp = current->next;
	            current->next = current->next->next;
	            delete temp;
	            cout << "Xoa khach hang thanh cong!" << endl;
	        } else {
	            cout << "Khach hang khong ton tai!" << endl;
	        }
	    }
	     bool kiemTraIDKhachHang(int id) {
	        NodeKhachHang* current = head;
	        while (current) {
	            if (current->data.id == id) {
	                return true;
	            }
	            current = current->next;
	        }
	        return false;
	    }
	
	    void capNhatKhachHang(int id) {
	        KhachHang* khachHang = timKhachHangTheoId(id);
	        if (khachHang) {
	            cout << "Nhap ten moi cua khach hang: ";
	            cin.ignore();
	            getline(cin, khachHang->ten);
	            
	            while (!kiemtraten(khachHang-> ten)) {
	            	cout << " Ten khach hang khong hop le! Ten khong chua duoc so. Vui long nhap lai: ";
	            	
	        		getline(cin, khachHang->ten);
				}
	            cout << "Nhap dien thoai moi cua khach hang: ";
	            getline(cin, khachHang->dienThoai);
	            cout << "Nhap email moi cua khach hang: ";
	            getline(cin, khachHang->email);
	            cout << "Cap nhat thong tin khach hang thanh cong!" << endl;
	        } else {
	            cout << "Khach hang khong ton tai!" << endl;
	        }
	    }
	
	    void sapXepKhachHangTheoTen() {
	        if (!head) return;
	        for (NodeKhachHang* i = head; i != nullptr; i = i->next) {
	            for (NodeKhachHang* j = i->next; j != nullptr; j = j->next) {
	                if (i->data.ten > j->data.ten) {
	                    swap(i->data, j->data);
	                }
	            }
	        }
	    }
	    
	    bool kiemTraIDKhachHang(int id, DanhSachKhachHang& dskh) {
    NodeKhachHang* current = dskh.head;
    while (current) {
        if (current->data.id == id) {
            return true;
        }
        current = current->next;
    }
    return false;
}
	
	    void sapXepKhachHangTheoId() {
	        if (!head) return;
	        for (NodeKhachHang* i = head; i != nullptr; i = i->next) {
	            for (NodeKhachHang* j = i->next; j != nullptr; j = j->next) {
	                if (i->data.id > j->data.id) {
	                    swap(i->data, j->data);
	                }
	            }
	        }
	    }
	};
	
	struct DanhSachSanPham {
	    NodeSanPham* head;
	
	    DanhSachSanPham() {
	        head = nullptr;
	    }
	
	    void themSanPham(SanPham sanPham) {
	        NodeSanPham* newNode = new NodeSanPham{sanPham, nullptr};
	        if (!head) {
	            head = newNode;
	        } else {
	            NodeSanPham* current = head;
	            while (current->next) {
	                current = current->next;
	            }
	            current->next = newNode;
	        }
	    }
	
	    SanPham* timSanPhamTheoId(int id) {
	        NodeSanPham* current = head;
	        while (current) {
	            if (current->data.id == id) {
	                return &current->data;
	            }
	            current = current->next;
	        }
	        return nullptr;
	    }
	
	    void hienThiSanPham() {
	        if (!head) {
	            cout << "Danh sach san pham trong!" << endl;
	            return;
	        }
	        NodeSanPham* current = head;
	        while (current) {
	            cout << "ID: " << current->data.id << " | Ten: " << current->data.ten
	                 << " | Gia: " << fixed << setprecision(2) << current->data.gia
	                 << " | So luong trong kho: " << current->data.soLuong << endl;
	            current = current->next;
	        }
	    }
	
	    void xoaSanPham(int id) {
	        if (!head) {
	            cout << "Danh sach san pham trong!" << endl;
	            return;
	        }
	        if (head->data.id == id) {
	            NodeSanPham* temp = head;
	            head = head->next;
	            delete temp;
	            cout << "Xoa san pham thanh cong!" << endl;
	            return;
	        }
	        NodeSanPham* current = head;
	        while (current->next && current->next->data.id != id) {
	            current = current->next;
	        }
	        if (current->next) {
	            NodeSanPham* temp = current->next;
	            current->next = current->next->next;
	            delete temp;
	            cout << "Xoa san pham thanh cong!" << endl;
	        } else {
	            cout << "San pham khong ton tai!" << endl;
	        }
	    }
	
	    void capNhatSanPham(int id) {
	        SanPham* sanPham = timSanPhamTheoId(id);
	        if (sanPham) {
	            cout << "Nhap ten moi cua san pham: ";
	            cin.ignore();
	            getline(cin, sanPham->ten);
	            cin >> sanPham->gia;
	            cout << "Nhap so luong moi cua san pham: ";
	            cin >> sanPham->soLuong;
	            cout << "Cap nhat thong tin san pham thanh cong!" << endl;
	        } else {
	            cout << "San pham khong ton tai!" << endl;
	        }
	    }
	
	    void sapXepSanPhamTheoGia() {
	        if (!head) return;
	        for (NodeSanPham* i = head; i != nullptr; i = i->next) {
	            for (NodeSanPham* j = i->next; j != nullptr; j = j->next) {
	                if (i->data.gia > j->data.gia) {
	                    swap(i->data, j->data);
	                }
	            }
	        }
	    }
	
	    void sapXepSanPhamTheoTen() {
	        if (!head) return;
	        for (NodeSanPham* i = head; i != nullptr; i = i->next) {
	            for (NodeSanPham* j = i->next; j != nullptr; j = j->next) {
	                if (i->data.ten > j->data.ten) {
	                    swap(i->data, j->data);
	                }
	            }
	        }
	    }
	
	    double tinhTongGia() {
	        double tong = 0;
	        NodeSanPham* current = head;
	        while (current) {
	            tong += current->data.gia * current->data.soLuong;
	            current = current->next;
	        }
	        return tong;
	    }
	
	    int tinhTongSoLuong() {
	        int tong = 0;
	        NodeSanPham* current = head;
	        while (current) {
	            tong += current->data.soLuong;
	            current = current->next;
	        }
	        return tong;
	    }

	
	bool kiemTraIDKhachHang(int id, DanhSachKhachHang& dskh);
	
	void nhapSoLuong(int& soLuong) {
	   while (true) {
        cout << "Nhap so luong san pham (so nguyen duong): ";
        cin >> soLuong;
        if (cin.fail() || !kiemTraSoLuong(soLuong)) {
            cin.clear();
            cout << "Nhap sai! So luong phai la mot so nguyen duong. Vui long nhap lai." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else {
            break;
        }
    
	}
}
};
	void menu(DanhSachKhachHang& dskh, DanhSachSanPham& dssp) {
	    int chon;
	    do {
	        cout << "\n--- MENU ---\n";
	        cout << "1. Them khach hang\n";
	        cout << "2. Them san pham\n";
	        cout << "3. Hien thi danh sach khach hang\n";
	        cout << "4. Hien thi danh sach san pham\n";
	        cout << "5. Tim khach hang theo ID\n";
	        cout << "6. Tim san pham theo ID\n";
	        cout << "7. Sap xep danh sach khach hang\n";
	        cout << "8. Sap xep danh sach san pham\n";
	        cout << "9. Xoa khach hang/san pham theo ID\n";
	        cout << "10. Tinh tong gia san pham\n";
	        cout << "11. Cap nhat thong tin khach hang\n";
	        cout << "12. Cap nhat thong tin san pham\n";
	        cout << "0. Thoat\n";
	        cout << "Chon: ";
	        
	        while (!(cin >> chon)) {
	            cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            cout << "Nhap sai! Vui long chon lai (Nhap 0 de thoat): ";
	        }
	
	        switch (chon) {
	            case 1: {
	                KhachHang khachHang;
	                cout << "Nhap ID: ";
	              
	          cin >> khachHang.id;
	         while (dskh.kiemTraIDKhachHang(khachHang.id)) {
	    cout << "ID da ton tai, vui long nhap id kh?c !" << endl;
	    cout << "Nhap ID: ";
	    cin >> khachHang.id;
	}
	                cin.ignore();
	                cout << "Nhap ten khach hang: ";
	                getline(cin, khachHang.ten);
	                while (!kiemtraten(khachHang.ten)) {
        			cout << "Ten khach hang khong hop le! Ten khong chua duoc so. Vui long nhap lai: ";
             		getline(cin, khachHang.ten);
    }

	                cout << "Nhap dien thoai: ";
	                getline(cin, khachHang.dienThoai);
	                cout << "Nhap email: ";
	                getline(cin, khachHang.email);
	                dskh.themKhachHang(khachHang);
	                break;
	            }
	            case 2: {
	                SanPham sanPham;
	                cout << "Nhap ID: ";
	                cin >> sanPham.id;
	                cin.ignore();
	                cout << "Nhap ten san pham: ";
	                getline(cin, sanPham.ten);
	                cout << "Nhap gia san pham: ";
	                cin >> sanPham.gia;
	                
	                 nhapSoLuong(sanPham.soLuong);
	                 dssp.themSanPham(sanPham);
	                break;
	            }
	            case 3:
	                dskh.hienThiKhachHang();
	                break;
	            case 4:
	                dssp.hienThiSanPham();
	                break;
	            case 5: {
	                int id;
	                cout << "Nhap ID khach hang: ";
	                cin >> id;
	                KhachHang* khachHang = dskh.timKhachHangTheoId(id);
	                if (khachHang) {
	                    cout << "ID: " << khachHang->id << " | Ten: " << khachHang->ten
	                         << " | Dien thoai: " << khachHang->dienThoai << " | Email: " << khachHang->email << endl;
	                } else {
	                    cout << "Khach hang khong ton tai!" << endl;
	                }
	                break;
	            }
	            case 6: {
	                int id;
	                cout << "Nhap ID san pham: ";
	                cin >> id;
	                SanPham* sanPham = dssp.timSanPhamTheoId(id);
	                if (sanPham) {
	                    cout << "ID: " << sanPham->id << " | Ten: " << sanPham->ten
	                         << " | Gia: " << fixed << setprecision(2) << sanPham->gia
	                         << " | So luong trong kho: " << sanPham->soLuong << endl;
	                } else {
	                    cout << "San pham khong ton tai!" << endl;
	                }
	                break;
	            }
	            case 7: {
	                int subChoice;
	                cout << "\n--- CHON LOAI SAP XEP ---\n";
	                cout << "1. Sap xep khach hang theo ten\n";
	                cout << "2. Sap xep khach hang theo ID\n";
	                cout << "3. Sap xep san pham theo gia\n";
	                cout << "4. Sap xep san pham theo ten\n";
	                cout << "0. Quay lai\n";
	                cout << "Chon: ";
	                cin >> subChoice;
	                switch (subChoice) {
	                    case 1:
	                        dskh.sapXepKhachHangTheoTen();
	                        break;
	                    case 2:
	                        dskh.sapXepKhachHangTheoId();
	                        break;
	                    case 3:
	                        dssp.sapXepSanPhamTheoGia();
	                        break;
	                    case 4:
	                        dssp.sapXepSanPhamTheoTen();
	                        break;
	                    case 0:
	                        break;
	                    default:
	                        cout << "Lua chon sai!" << endl;
	                }
	                break;
	            }
	            case 8:
	                dssp.hienThiSanPham();
	                break;
	            case 9: {
	                int subChoice;
	                cout << "\n--- CHON LOAI XOA ---\n";
	                cout << "1. Xoa khach hang theo ID\n";
	                cout << "2. Xoa san pham theo ID\n";
	                cout << "0. Quay lai\n";
	                cout << "Chon: ";
	                cin >> subChoice;
	                switch (subChoice) {
	                    case 1: {
	                        int id;
	                        cout << "Nhap ID khach hang can xoa: ";
	                        cin >> id;
	                        dskh.xoaKhachHang(id);
	                        break;
	                    }
	                    case 2: {
	                        int id;
	                        cout << "Nhap ID san pham can xoa: ";
	                        cin >> id;
	                        dssp.xoaSanPham(id);
	                        break;
	                    }
	                    case 0:
	                        break;
	                    default:
	                        cout << "Lua chon sai!" << endl;
	                }
	                break;
	            }
	            case 10:
	                cout << "Tong gia tri san pham trong kho: " << fixed << setprecision(2) << dssp.tinhTongGia() << endl;
	                break;
	            case 11: {
	                int id;
	                cout << "Nhap ID khach hang can cap nhat: ";
	                cin >> id;
	                dskh.capNhatKhachHang(id);
	                break;
	            }
	            case 12: {
	                int id;
	                cout << "Nhap ID san pham can cap nhat: ";
	                cin >> id;
	                dssp.capNhatSanPham(id);
	                break;
	            }
	            case 0:
	                cout << "Thoat chuong trinh!" << endl;
	                break;
	            default:
	                cout << "Lua chon sai! Vui long chon lai.\n";
	        }
	    } while (chon != 0);
	}
	
	int main() {
	    DanhSachKhachHang dskh;
	    DanhSachSanPham dssp;
	
	    menu(dskh, dssp);
	
	    return 0;
	} 