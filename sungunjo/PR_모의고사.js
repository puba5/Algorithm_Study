function solution(answers) {
    var answer = [];
    
    var supoza = {
        pattern: [],
        score: 0,
        
        scoreUp: function() {
            this.score += 1;
        },
    
        setPattern: function (pat) {
            this.pattern = pat;
        }
    };
    
    var create_object = function (O) {
        function F () {};
        F.prototype = O;
        return new F();
    };
    
    
    var one = create_object(supoza);
    one.setPattern([1, 2, 3, 4, 5]);

    var two = create_object(supoza);
    two.setPattern([2, 1, 2, 3, 2, 4, 2, 5]);

    var three = create_object(supoza)
    three.setPattern([3, 3, 1, 1, 2, 2, 4, 4, 5, 5]);
    
    for (var i in answers) {
        if (answers[i] == one.pattern[i % one.pattern.length]) {
            one.scoreUp();
        }
        if (answers[i] == two.pattern[i % two.pattern.length]) {
            two.scoreUp();
        }
        if (answers[i] == three.pattern[i % three.pattern.length]) {
            three.scoreUp();
        }
    }
    
    var max_score = Math.max(one.score, two.score, three.score);
    
    if (one.score === max_score) {
        answer.push(1);
    }
    if (two.score === max_score) {
        answer.push(2);
    }
    if (three.score === max_score) {
        answer.push(3);
    }
    return answer;
}