QHĐ cổ điển:
	LIS
	knapsack (cái túi)
		có n đồ vật, wi trọng lượng, vi giá trị, hỏi: làm sao lấy tổng khối lượng đồ vật lấy không quá S, tổng giá trị lấy là lớn nhất có thể
	Lưới, ma trận

### subset sum: (b04, b15)  Dãy con có tổng bằng S: dp[i] = 0 / 1
- dp[0] = 1 (tap rong)
- moi phan tu trong mang duoc dung nhieu lan: xay dung từ đầu
- dùng mot lan duy nhat: xây từ cuối trở lại
- y tuong: xét từng phần tử trong mảng => dp[i] = dp[cho xet] - a[i] neu == 1 thi dp[i] = 1

### Cái túi (b08)
- dp[i] [j] = giá trị lớn nhất của túi khi chọn i đồ vật đầu tiên, với trọng lượng không vượt quá j
- hai cách chọn: so sánh lấy hay không lấy cách có giá trị lớn hơn thì chọn
	- không lấy: f[i] [j] = f[i-1] [j]
	- lấy: (điều kiện: ) f[i] [j] = f[i-1] [j -w[i]] + v[i]