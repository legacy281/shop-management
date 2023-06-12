#ifndef DE8EFC43_B901_4ABB_9599_FD9F8A596A29
#define DE8EFC43_B901_4ABB_9599_FD9F8A596A29
//Cấu trúc dữ liệu của một Node đơn hàng
struct Node
{
    /*Receipt_Number: Mã đơn hàng 
    X: Số loại máy mà khách hàng muốn mua
    */
    int Receipt_Number, X;
    
    /*
    Customer_Name: Tên khách hàng
    Date: Ngày
    */
    wstring Customer_Name, Date, Password=L"PBL8888";
    
    //Mật khẩu đăng nhập vào giao diện Nhân viên
    bool Pass=false;

    /*
    Quantity: Số lượng của từng loại máy 
    Menu2: Biến dùng để lưu lại Mã đơn hàng 
    */
    int Quantity[10],Menu2[10];
    
    /*
    Amount: Số tiền phải trả từng loại máy
    Total: Tổng tiền phải trả của đơn hàng
    Revenue: Doanh thu
    */
    float Amount[10], Total, Revenue=0;

    //Số loại máy tính
    int Quant=10;
    
    int ID[100]=
        {
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8,
            9,
            10
        };
        
    wstring Computer_Name[100]=
        {
            L"Asus VivoBook  ",
            L"MSI Gaming     ",
            L"Dell Inspiron  ",
            L"Dell Xps       ",
            L"MacBook pro    ",
            L"LG Gram        ",
            L"Lenovo Thinkpad",
            L"Surface Book 3 ",
            L"Acer Nitro 5   ",
            L"HP Yoga 4      "
        };
    
    wstring  CPU[100]=
        {
            L"Intel I5 8086U",
            L"Intel I5 1050H",
            L"Intel T7 1165G7",
            L"Intel I7 1130H",
            L"Apple M1      ",
            L"Intel I7 1084U",
            L"Intel I7 1038U",
            L"Intel I7 1050H",
            L"Ryzen 5 5600U ",
            L"Intel I7 1165G7"
        };
        
    wstring RAM[100]=
        {
            L"8GB ",
            L"8GB ",
            L"16GB",
            L"8GB ",
            L"8GB ",
            L"8GB ",
            L"16GB",
            L"8GB ",
            L"8GB ",
            L"8GB "
        };
        
    wstring ROM[100]=
        {
            L"HDD 512GB",
            L"SSD 512GB",
            L"SSD 1TB  ",
            L"HDD 512GB",
            L"SSD 512GB",
            L"SSD 1TB  ",
            L"SSD 512GB",
            L"SSD 512GB",
            L"SSD 1TB ",
            L"HDD 1TB  "
        };
    //Price: Giá  (Triệu đồng)
    int Price_Computer[100]=
        {
            19,
            25,
            45,
            33,
            40,
            32,
            43,
            59,
            29,
            22
        };
    
    //All: Số lượng từng loại máy
    int All[100]=
        {
            29,
            35,
            14,
            23,
            30,
            19,
            24,
            7,
            40,
            26
        };

    //Save: Lưu lại số lượng để kiểm tra doanh thu và đánh giá
    int Save[100]=
        {
            29,
            35,
            14,
            23,
            30,
            19,
            24,
            7,
            40,
            26
        };
        
    Node *PNext;//Cấp phát vùng nhớ
} *P, *Tempp;  //Tempp là con trỏ lưu dữ liệu Order

Node *Temp=new Node; //Temp là con trỏ thay đổi dữ liệu Node
Node *Start_Ptr=NULL; //Trỏ đến đơn hàng cuối cùng: Start-3-2-1-NULL
Node *PHead=NULL;
Node *PTail=NULL;

#endif /* DE8EFC43_B901_4ABB_9599_FD9F8A596A29 */
