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
        GameObject::vec.push_back(this);
    }
    virtual void update(int NewPosition, int NewHealth, int NewSprite)
    {
        std::cout << "---------GAMEOBJECT UPDATE---------\n";
        this->position = NewPosition;
        this->health = NewHealth;
        this->sprite = NewSprite;
    }

    int GetPosition()
    {
        return position;
    }

    virtual bool CollisionDetect()
    {
        std::cout << "GAMEOBJECT COLLISION DETECTION...\n";
        for (int i = 0; i < this->vec.size(); i++)
        {
            for (int j = 0; j < this->vec.size(); j++)
            {
                if (i != j && GameObject::vec[i]->GetPosition() == GameObject::vec[j]->GetPosition())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

std::vector<GameObject*> GameObject::vec = {};

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
        std::cout << "PLAYER COLLISION DETECTION...\n";
        for (int i = 0; i < this->vec.size(); i++)
        {
            for (int j = 0; j < this->vec.size(); j++)
            {
                if (i != j && GameObject::vec[i]->GetPosition() == GameObject::vec[j]->GetPosition())
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
        std::cout << "ENEMY COLLISION DETECTION...\n";
        for (int i = 0; i < this->vec.size(); i++)
        {
            for (int j = 0; j < this->vec.size(); j++)
            {
                if (i != j && GameObject::vec[i]->GetPosition() == GameObject::vec[j]->GetPosition())
                {
                    return true;
                }
            }
        }
        return false;
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
        std::cout << "OBSTACLE COLLISION DETECTION...\n";
        for (int i = 0; i < this->vec.size(); i++)
        {
            for (int j = 0; j < this->vec.size(); j++)
            {
                if (i != j && GameObject::vec[i]->GetPosition() == GameObject::vec[j]->GetPosition())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Player b1(1,2,3);
    Enemy c1(2,2,3);
    std::cout<<b1.CollisionDetect();
}
