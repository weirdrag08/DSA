class AuctionSystem {
public:
     // {user id, itemid} = bid amount
    map<pair<int, int>, int> memory;
    //{item, {bidAmount, userId}}
    unordered_map<int, set<pair<int, int>, greater<pair<int, int> > > > itemMemory;
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
       if(memory.count(make_pair(userId, itemId)) > 0){
            //delete the old entry from item memory before updating the bid if bid already exists
           int oldBid = memory[make_pair(userId, itemId)];
           itemMemory[itemId].erase(make_pair(oldBid, userId));
       }
        //update the memory & itemMemory
        memory[make_pair(userId, itemId)] = bidAmount;
        itemMemory[itemId].insert(make_pair(bidAmount, userId));
    }
    
    //It is given that the bid will already exist
    void updateBid(int userId, int itemId, int newAmount) {
        //delete the old entry from item memory before updating the bid if bid already exists
        int oldBid = memory[make_pair(userId, itemId)];
        itemMemory[itemId].erase(make_pair(oldBid, userId));
        //update memory and itemMemory
        memory[make_pair(userId, itemId)] = newAmount;
        itemMemory[itemId].insert(make_pair(newAmount, userId));
        
    }

    //The record is guaranteed to exist
    void removeBid(int userId, int itemId) {
        //Remove from itemMemory first
        int currBid = memory[make_pair(userId, itemId)];
        itemMemory[itemId].erase(make_pair(currBid, userId));
        //If there is no bid for the current item id, remove key from itemMemory
        if(itemMemory[itemId].size() == 0){
            itemMemory.erase(itemId);
        }
        
        //Remove from memory
        memory.erase(make_pair(userId, itemId));
    }
    
    int getHighestBidder(int itemId) {
        //If the bid for the item exists, return the userId of the first object in the set
        if(itemMemory.count(itemId) > 0){
            return itemMemory[itemId].begin()-> second; 
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
