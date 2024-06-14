$(function () {
    let levels = $('tr').find('.level');
    console.log(levels.length);
    for (let i=0;i<levels.length;i++) {
        let level = levels.eq(i);
        setEasy(level);
        setNomal(level);
        setHard(level);
    }
});

function setEasy(level) {
    if (level.text() == '低') {
        console.log(level.text());
        level.addClass('easy');
    }
}

function setNomal(level) {
    if (level.text() == '中') {
        console.log(level.text());
        level.addClass('nomal');
    }
}

function setHard(level) {
    if (level.text() == '高') {
        console.log(level.text());
        level.addClass('hard');
    }
}
