# personal-project
```
Repository for my personal project - text game ish
```
# How to play
```
when you run this program from ide(cpp file is in src), each lines will show up on the terminal to explain what you can do.
You can follow the descriptions to play.
For most of the cases, you can just type in a number that
corresponds to the selection of your choice instead of typing in a whole word.
```
# Mode selection
you can select what mode you want to play out of two modes:
1. normal mode
2. versus mode

# 1. Normal mode
```
You can select which character you want to train. Each character will have
different initial status, and whoever you pick, you will be given 20 turns of training before the race.
The final race's opponent is named Arone, who has a fixed status for all characters.
After the final race, your character will be included into a list of graduated character,
no matter if you won or lost the final battle.
```

1-1. Training
```
During turns, you have following things:
current_hp value;
training selections;
taking a break;
```
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

```
Taking a break
Recovers current_hp value. Intellect training also recovers the current_hp value,
but taking a break recovers much more value.
```

1-2. Race
```
On terminal, your character and opponent character's name and stats will be displayed.
After you type in anything to the terminal, the race will begin.
```
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
# 2. versus mode
```
you can select two character out of all characters you trained.
You can see which character that you trained can run faster.
* you can see the same characters during selection, but cannot select them twice in a row.
However, just characters with the same name can be selected in a row.
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
