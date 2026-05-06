class Solution {
public:
    int maxProfit(vector<int>& prices) {
      //prices[3] is basically  the price for the 3rd day  & so on.
      //want to choose the ith day which has the max profit. return that value
      //ex, buy on day 2 with the lowest price but find a price greater to sell for later that day, return
      //which day is cheapest to buy with greater values later
      //otherwise, return 0. ex edge case: listed in descending order, no possible profit.
//++x doesnt create a temp copy

/*What's the cheapest price I've seen so far? (to know the best buy day)
What's the maximum profit I've found so far? (to keep track of the best deal)*/
int cheapest = prices.front();
int max_profit = 0;
int profit = 0;
       
for (int x=0; x < prices.size();++x){
 // Step 1: Is today cheaper than the cheapest I've seen?
    // If yes, update cheapest
            if (prices[x] < cheapest){
            cheapest = prices[x];
            }
   /// Step 2: What profit would I get if I SELL today?
    // (Hint: today's price MINUS what?)
        else if ((prices[x]- cheapest)> 0 ){
         profit = prices[x]- cheapest;
         max_profit += profit;
         cheapest = prices[x];
       }
          // Step 3: Is this profit better than maxProfit? 
          // In this problem, we accumulate profits from every increase.
         } 
          return max_profit;
    }

};