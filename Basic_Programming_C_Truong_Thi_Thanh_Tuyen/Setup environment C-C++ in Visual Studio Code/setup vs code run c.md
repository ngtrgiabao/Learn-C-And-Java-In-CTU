# Hướng dẫn cài setup môi trưởng chạy C/C++ trên VS Code

- 1.  tải visual studio code: Tải 2 extention {C/C++, Code runner}
- 2.  tải mingw.exe (giải nén file mingw-17.1-without-git.rar và đặt vào thư mục: C:\MingW)
- 3.  Mở thư mục bin trong MingW, sao chép đường dẵn của thư mục (ex. C:\MingW\bin)
- 4.  Cài đặc biến môi trường trong windows 10:
  - Mở This PC -> Poperties -> Advance system setting
    -> Environment Viriable -> chose Path -> edit -> new
    -> paste link to folder bin (in MingW)
    -> ok -> ok
    => Như vậy là cài đặc biến môi trường xong.
- 5.  Một số lỗi có thể xảy ra:
  - Bug: Không thể nhập thứ text ở trong terminal
    -> Chọn mục file -> references -> setting -> gõ cụm: "run in terminal"
    -> Chọn mục: "Code runner: run code in terminal"
    -> Click chọn tick mục: "whatever ... terminal"

---

**Chúc mai mắn!**
