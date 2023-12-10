# personal-project
```
Repository for my personal project - Runner Maker
```
# How to play
```
when you run this program from ide(cpp file is in src),
each lines will show up on the terminal to explain what you can do.
You can follow the descriptions to play.
For most of the cases, you can just type in a number that
corresponds to the selection of your choice instead of typing in a whole word.
```
# Mode selection
you can select what mode you want to play out of two modes:
1. normal mode
2. versus mode

![mode selection](https://github.com/Eunchan-Koh/personal-project/assets/80871891/926c6b01-2e71-4728-8058-7e07bcb5ba3d)


# 1. Normal mode
```
You can select which character you want to train. Each character will have
different initial status, and whoever you pick, you will be given 20 turns of training before the race.
The final race's opponent is named Arone, who has a fixed status for all characters.
After the final race, your character will be included into a list of graduated character,
no matter if you won or lost the final battle.
```
![3](https://github.com/Eunchan-Koh/personal-project/assets/80871891/facbc396-78cf-4b2b-be22-edc2270f1fe7)


1-1. Training
```
During turns, you have following things:
current_hp value;
training selections;
taking a break;
```
![4](https://github.com/Eunchan-Koh/personal-project/assets/80871891/a46a0a88-ffed-46e4-809d-880950b3d471)


Current_hp
```
current_hp value affects to the percentage of the character finishing his training successfully.
When your character's current_hp value is low, training success rate goes below 100%, Max to 0%.
The calculation is made using random number generator function.
```

Training
```
When you select one of the five types of training, your character's stat
values related to the training increase.
At the same time, your character's current_hp value decreases(spends current hp value).
When you do the same type of training for 5 times in total, that type of training level increases,
and your character will have greater stat value increasement from the same type of training.
Up to lv.5, but not possible yet.
```

Taking a break
```
Recovers current_hp value. Intellect training also recovers the current_hp value,
but taking a break recovers much more value.
```

1-2. Race
```
On terminal, your character and opponent character's name and stats will be displayed.
After you type in anything to the terminal, the race will begin.
```
![1](https://github.com/Eunchan-Koh/personal-project/assets/80871891/322817b5-ac18-4938-a7a0-eda2e5dd0c1c)

Track
```
Track contains two types of floors:
1. Flat floor
2. Uphill floor
```
Flat floor
```
speed and power of the character affects to the distance/sleep. Spends stamina value,
and when stamina goes below 50, speed slows down.
will be represented as '-'.
```
Uphill floor
```
power affects more to the distance/sleep compared to the flat floor. Spends greater amount of
stamina value, and when stamina goes below 50, speed slows down.
will be represented as '^'
```
Character
```
each character will be represented by character 'o' on track. 
```
Winner
```
After the race, winner's name will be displayed on terminal. After this, your character will
be listed on the graduated runner list, becomes selectable on 2nd mode.
```
![2](https://github.com/Eunchan-Koh/personal-project/assets/80871891/2313c4f1-c2b1-4785-977f-86ad4fd40b97)

# 2. versus mode
```
you can select two character out of all characters you trained.
You can see which character that you trained can run faster.
* you can see the same characters during selection, but cannot select them twice in a row.
However, just characters with the same name can be selected in a row.
```
![versus1](https://github.com/Eunchan-Koh/personal-project/assets/80871891/ccd24b5a-9c83-4237-9199-cd8b03130e5a)
![versus2](https://github.com/Eunchan-Koh/personal-project/assets/80871891/1acfa0fc-c298-435f-aab2-db4230763a29)




# After each mode ends
```
You can keep playing if you want. After each mode ends, terminal will ask your intention.
If you want to play again, type in 'Y'. You will go to mode selection page again.
If you want to quit, type in 'N'. The game will say good bye to you.
```
# What can be developed further
1. Usage of will and intellect stats. They do not have any role in my code yet, but can add role during race.
2. Types of running. Depends on types of running for each character, the speed formula can be varied instead of making all of them having the same spped formula.
3. Types of Track. There are only one track in this code so far, but can add multiple numbers of track and choose one of them by rng.
4. Events. can make various events and make them happen randomly, such as recovering current_hp value during training with event explanation.
5. Supporter. can add supporter selection page and make them randomly come to one of the training selections. each of them can have different effects, such as A making max_hp value increased, B reduce the amount of current_hp spend per training and such.
6. Multiple character race. Instead of making race 1vs1, can make multiple characters to run at once.
7. Save and Load. so graduated runner list can be saved to an external file to save the data even after the game is turned off.
8. Custom character creation. Can make the user to create a custome character with custom name and custom initial stats.
9. Add more turns and races until graduate. Currently, there are only 20 turns and 1 race until graduation for normal mode. can add much more number of turns and races.


# Reference:
```
This project is started from game called Umamusume. I used to play that game and wondered
if I can make this game using my own code, so lots of idea & terms came from that game.
```
