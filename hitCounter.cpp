/*
362. Design Hit Counter
DescriptionHintsSubmissionsDiscussSolution
Pick One
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?

*/

class HitCounter {
    vector<int> time;
    vector<int> hitCount;
public:
    /** Initialize your data structure here. */
    HitCounter() {
       vector<int> temp(300, 0);
       time = temp;
       hitCount = temp;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int bucket = timestamp % 300;
        if (time[bucket] != timestamp) {
            time[bucket] = timestamp;
            hitCount[bucket] = 1;
        } else {
            hitCount[bucket] +=1;
        }          
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {       
        int total =0;
        for(int i=0; i<300; i++) {
            if(timestamp - time[i] < 300) {
                total += hitCount[i];
            }      
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
