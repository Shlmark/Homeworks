#include <iostream>
#include <vector>
class GameObject
{
protected:
    int position;
    int health;
    int sprite;
    static std::vector<GameObject*> vec;
public:
    GameObject()
    {
        this->position = 0;
        this->health = 0;
        this->sprite = 0;
    }

    GameObject(int position, int health, int sprite)
    {
        this->position = position;
        this->health = health;
        this->sprite = sprite;
        vec.push_back(this);
    }

    virtual void update(int NewPosition, int NewHealth, int NewSprite)
    {
        std::cout << "---------GAMEOBJECT UPDATE---------\n";
        this->position = NewPosition;
        this->health = NewHealth;
        this->sprite = NewSprite;
    }

    virtual bool CollisionDetect()
    {
        std::cout << "GAMEOBJECT COLLISION DETECTION...";
        for (int i = 0; i < this->vec.size(); i++)
        {
            for (int j = 0; j < this->vec.size(); j++)
            {
                if (this->vec[i]->position == this->vec[j]->position)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Player : public GameObject
{
public:
    Player() : GameObject()
    {

    }

    Player(int position, int health, int sprite) : GameObject(position, health, sprite)
    {

    }

    void update(int NewPosition, int NewHealth, int NewSprite) override
    {
        std::cout << "---------PLAYER UPDATE---------\n";
        this->position = NewPosition;
        this->health = NewHealth;
        this->sprite = NewSprite;
    }

    bool CollisionDetect() override
    {
        std::cout << "PLAYER COLLISION DETECTION...";
        for (int i = 0; i < this->vec.size(); i++)
        {
            for (int j = 0; j < this->vec.size(); j++)
            {
                if (this->vec[i]->position == this->vec[j]->position)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Enemy : public GameObject
{
public:
    Enemy() : GameObject()
    {

    }

    Enemy(int position, int health, int sprite) : GameObject(position, health, sprite)
    {

    }

    void update(int NewPosition, int NewHealth, int NewSprite) override
    {
        std::cout << "---------ENEMY UPDATE----------\n";
        this->position = NewPosition;
        this->health = NewHealth;
        this->sprite = NewSprite;
    }

    bool CollisionDetect() override
    {
        std::cout << "ENEMY COLLISION DETECTION...";
    }
};

class Obstacle : public GameObject
{
public:
    Obstacle() : GameObject()
    {

    }

    Obstacle(int position, int health, int sprite) : GameObject(position,health,sprite)
    {

    }

    void update(int NewPosition, int NewHealth, int NewSprite) override
    {
        std::cout << "---------OBSTACLE UPDATE-------\n";
        this->position = NewPosition;
        this->health = NewHealth;
        this->sprite = NewSprite;
    }

    bool CollisionDetect() override
    {
        std::cout << "OBSTACLE COLLISION DETECTION...";
    }
};

int main()
{
    Player a(1,1,3);
    Enemy b(2,1,2);
    Obstacle c(3,2,1);
    std::cout<<a.CollisionDetect();
}
