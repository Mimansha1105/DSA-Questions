class EventManager {
public:
    unordered_map<int, int> mp;
    struct cmp{
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            if(a.first==b.first)
                return a.second>b.second;
            return a.first<b.first;
        }
    };
    priority_queue<pair<int, int>,vector<pair<int , int>>, cmp> pq;
    EventManager(vector<vector<int>>& events) {
        for(auto &e: events){
            int id=e[0], p=e[1];
            mp[id]=p;
            pq.push({p,id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority, eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto[p,id]=pq.top();
            pq.pop();
            if(mp.count(id) && mp[id]==p){
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */