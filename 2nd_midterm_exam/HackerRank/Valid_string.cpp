string isValid(string s) {
int count[26] = {0};

    for (int i = 0; i < s.length(); i++) { 
        count[s[i] - 'a']++;     // հաշվում ենք տառերի քանակը, a-ն հանում ենք, ստանում ինդեքս

    }

    int qanak = 0;        // հիմնական քանակը
    int diff_Count = 0;   //տարբերների քանակը

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {   //վերցնում ենք 1-ին 0ից տարբեր քանակը
            qanak = count[i];
            break;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0 && count[i] != qanak) { //անցնում ենք այն տառերի վրայով , որոնք կան string-ում և որոնց քանակը տարբերվում է հիմնական քանակից
            if (count[i] == 1 || count[i] == qanak + 1)   // եթե տառը 1 անգամ է կամ 1-ով շատ է կարելի է ջնջել

                diff_Count++;
            else
                return "NO";
        }
    }

  
    if (diff_Count > 1)      // եթե մեկից շատ տառ է տարբերվում NO
        return "NO";

    return "YES";
}
