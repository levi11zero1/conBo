# Game conBo - Bắn xe tăng cổ điển 
- Link video demo game: https://drive.google.com/file/d/1AfMpLrBvcF46COfaPCBAIkwKibFKh5ur/view?usp=sharing
## 1. Giới thiệu game:
**conBo** là game bắn xe tăng cổ điển lấy cảm hứng từ tựa game BattleCity. Trong game người chơi sẽ điều khiển xa tăng bắn hạ nhiều kẻ địch nhất có thể và bảo vệ căn cứ. Trò chơi có lối chơi đơn giản nhưng cũng đầy thử thách, yêu cầu người chơi vừa tấn công vừa phòng thủ một cách linh hoạt. Trò chơi có các mức level khác nhau để người chơi có thể lựa chọn nhằm thử thách bản thân, mang lại trải nghiệm thú vị và đầy tính chiến thuật.

## 2. Cách chơi game
Sau khi bắt đầu trò chơi trên màn hình sẽ xuất hiện menu như sau:

![image](https://github.com/user-attachments/assets/a351fe7e-b844-4441-80e9-e3e8cb4b1f8b)

Bạn sẽ nhấn các nút **1 2 3 4** để chọn level chơi, level càng cao thì càng khó. Số level sẽ tương ứng với số kẻ địch xuất hiện trong game của bạn.
Sau khi đã chọn level bạn sẽ nhấn Enter để bắt đầu chơi hoặc nếu không thích chơi nữa có thể nhấn Space để thoát game.

Sau khi nhấn **Enter** game sẽ bắt đầu với giao diện như sau:

![image](https://github.com/user-attachments/assets/77c7fd73-7acc-4092-ac3b-daf0485bf149)

Nhiệm vụ của bạn là bảo vệ căn cứ ( phía dưới chính giữa ) và tiêu diệt xe tăng địch. 

Sử dụng 4 phím **◄ ► ▲ ▼** để di chuyển và phím **J** để bắn. Trên bản đồ game có các chướng ngại vật là tường gạch đỏ và tường gạch trắng trong đó bạn có thể bắn nổ tường gạch đỏ để tạo thêm phạm vi di chuyển cho bản thân.

Sau mỗi lần bạn tiêu diệt được xe tăng dịch điểm ở góc phải của bạn sẽ tăng lên 1 và ngay phía dưới là điểm cao nhất bạn đã từng đạt được qua các màn chơi.

Trò chơi sẽ kết thúc nếu bạn hoặc căn cứ của bạn bị tiêu diệt và chuyển sang màn hình **GAME OVER**: 

![image](https://github.com/user-attachments/assets/39a6d587-3bb1-4251-b110-c86b9812fc2a)

Ở đây là hiển thị số điểm bạn đạt được trong vòng chơi vừa rồi. Tại đây bạn có thể nhấn **Enter** để chơi lại hoặc **Space** để thoát game.

## 3. Cấu trúc source code:
- File header : chứa các phần định nghĩa và khai báo hàm, lớp , các hằng số , ..
- File cpp : gồm các file định nghĩa các hàm đã khai báo trong file header và 1 file main.cpp để chạy chương trình chính.
- Các file khác để trong thư mục asset ; chứa các file ảnh (,jpg, .png), các file âm thanh (.mp3, .wav), các file font chữ (.ttf)

## 4. Các nguồn tham khảo:
- Đồ họa: https://www.spriters-resource.com/nes/batcity/sheet/60016/
- Âm thanh: https://www.nhaccuatui.com/bai-hat/battle-city-nes-nhac-chuong-various-artists.b0xSqpHeGM1Q.html
- Font chữ: https://inkythuatso.com/mau-thiet-ke-vector/font-ttf-3603.html?srsltid=AfmBOooF3l0hXcJllx_62oqzO7-rHxpRQFmFDOcNp28TzoA9rCRLytMA
- Cách xử lí va chạm và xây dựng map: https://www.youtube.com/c/Ph%C3%A1tTri%E1%BB%83nPh%E1%BA%A7nM%E1%BB%81m123AZ
- Hỏi đáp trong quá trình code: https://chatgpt.com/








