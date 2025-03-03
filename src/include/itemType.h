#include <unordered_map>
#include <vector>
#include <optional>
#include <string>
#include <random>
#pragma once

class postac;

enum class itemType
{
    Boots,
    Leggings,
    Chestplate,
    Helmet,
    Gloves,
    Ring,
    Necklace,
    Weapon
};

struct itemStats
{
    std::string name;
    itemType type;
    int hpmin=0;
    int hpmax=0;
    int hp=0;
    int admin=0;
    int admax=0;
    int ad=0;
    int defmin=0;
    int defmax=0;
    int def=0;
    int manamin=0;
    int manamax=0;
    int mana=0;
    int speedmin=0;
    int speedmax=0;
    int speed=0;
    int itemLvl=1;
    int price=20;
    bool isArtifact=false;
};

extern std::unordered_map<int, itemStats> itemData;

class Item
{
friend class postac;

private:
    int id;
    itemStats stats=itemData.at(id);
    std::mt19937 gen;
public:
    Item(int ItemId): id(ItemId)
    {
        stats = itemData.at(ItemId);
    }

    itemStats getStats() const;
    void generateStats(std::mt19937& gen, postac*& hero);
    int getId() const;
    itemType getType() const;
    std::string getTypeString() const;
};

class Inventory
{
friend class postac;

private:
    std::vector<Item> items;
public:
    void addItem(const Item& item);
    void removeItem(int index);

    std::optional<Item> getItemByIndex(size_t index) const;
    void printInv() const;
    int getInvSize() const;
};
