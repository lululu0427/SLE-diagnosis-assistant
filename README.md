# SLE-diagnosis-assistant

###版本6:<br>
1.將程式模組化，從原先598行縮減至84行，不過還有進步空間<br>
###版本5:<br>
1.使用者可輸入題號修改指定題目的答案<br>
2.調整排版<br>
3.新增輸入病人基本資料<br>
4.自動儲存至Excel，儲存病人基本資料，當下時間，答題記錄，SLE以及SLEDAI分數<br>
### 8/8 版本4:<br>
1.詢問病人是否已診斷為SLE，是的話將跳至SLEDAI的問題，最後會印出病患activity程度<br>
2.在Clinical以及Immunology兩個domain回答完時，會分別顯示每個問題的輸入結果，此時可確認是否有誤可回頭更改<br>
3.全部輸入完最後會再問是否要confirm以及修改，是的話會一題一題print題目跟先前答案<br>
### 7/18 版本3:<br>
1.新增F鍵，輸入F即可跳至下一題，在clinical domain 以及Immunology domain輸入完後若有未輸入Y或N的題目，會分別顯示出missing value並請使用者再度確認答案<br>
2.移除main cause<br>
3.將防呆再次優化(上個版本反覆輸入B或F在一些條件下會出現bug)<br>
4.新增SLEDAI，在判定為SLE後會有額外關於SLEDAI的問題<br>

### 7/2 版本2:<br>
1.主架構大改並將weight、domain及症狀都存入陣列，方便維護且code較為精簡(行數不到版本一的一半)<br>
2.強化防呆裝置，entry criterion 輸入負數或是文字時會給予提醒並要求重新輸入<br>
3.除了Y跟N以外，新增B键，輸入B即可回到上一題，可持續輸入直到第一題，先前的版本若是Y要改成N要從頭重新輸入<br>
4.因SLE classification 至少需要 1 clinical criterion，設立flag當沒有clinical criterion會提醒使用者<br>
5.若是判定為SLE，會告訴使用者主因以及該主因weight佔total score的比例<br>

### 6/27 版本1:<br>
1.透過for跟switch作為主架構，先讓主程式有基本功能<br>
2.簡單的防呆裝置，Y﹑N以外的輸入會再跑一次問題<br>
