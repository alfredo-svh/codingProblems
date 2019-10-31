/*
	meanGroups function:

	input: 2d array of integers
	output: 2d array of integers

	Details: This function takes a 2d array of integers.
	We need to calculate the mean of each array and group
	these arrays according to their mean.
	The returning 2d array consists of arrays containing the
	indexes of the original arrays.
	They will be ordered in an increasing fashion.
*/


std::vector<std::vector<int>> meanGroups(std::vector<std::vector<int>> a) {
    std::vector<std::vector<int>> b;
    std::map<float, int> means;
    float curMean;
    
    
    for(int i=0;i<a.size();i++){
        curMean=0;

		/* we calculate and save the mean
		   for every integer in each array
		*/
        for(int j=0;j<a[i].size();j++){
            curMean+=a[i][j];
        }
        curMean/=a[i].size();
        
		/* we try to insert this mean into our map, with a corresponding value
		   of its index in the new 2d array.
		   If it succeeds and it is a new mean,
		   we create a new array in the new 2d array
		   and push the original index of the current array.
		   If it fails and we have already seen that mean,
		   we use our map to push the original index of the current
		   array to the correct group in the new 2d array.
		*/ 
        if(means1.insert(std::pair<float, int>(curMean, b.size())).second==true){
            b.push_back(std::vector<int>());
            b[b.size()-1].push_back(i);
        }
        else
			b[means[curMean]].push_back(i);

    }
    

    return b;
}