# SLE-diagnosis-assistant
### 6/27 版本1:<br>
1.透過for跟switch作為主架構，先讓主程式有基本功能<br>
2.簡單的防呆裝置，Y﹑N以外的輸入會再跑一次問題<br>

### 7/2 版本2:<br>
1.主架構大改並將weight、domain及症狀都存入陣列，方便維護且code較為精簡(行數不到版本一的一半)<br>
2.強化防呆裝置，entry criterion 輸入負數或是文字時會給予提醒並要求重新輸入<br>
3.除了Y跟N以外，新增B選項，輸入B即可回到上一題，可持續輸入直到第一題，先前的版本若是Y要改成N要從頭重新輸入<br>
4.因SLE classification 至少需要 1 clinical criterion，設立flag當沒有clinical criterion會提醒使用者<br>
5.若是判定為SLE，會告訴使用者主因以及該主因weight佔total score的比例<br>
