int hourglassSum(vector<vector<int>> arr) {
   int max_sum = -63; 
    for (int i = 0; i <= 3; i++) {     
        for (int j = 0; j <= 3; j++) {   
            int final_sum = 
                arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                arr[i+1][j+1] +
                arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            
            if (final_sum > max_sum)
                max_sum = final_sum;
        }
    }
    return max_sum;
}
