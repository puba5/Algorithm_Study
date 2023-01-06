//  "aya", "ye", "woo", "ma" 네 가지로 이루어진 string인지 확인

const CanSay = ["aya", "ye", "woo", "ma"];

const checkCanSay = (word) => {

    while(word.length !== 0){
        let isMatched = false;
        CanSay.forEach((canSayWord)=>{
            if(word.substring(0,canSayWord.length) ===canSayWord){
                word = word.substring(canSayWord.length);
                isMatched = true;
            }
        })

        if(isMatched) continue;
        
        return false;
    }
    return true;
}

const solution = (babbling) => {
    return babbling.filter((word)=>{
        return checkCanSay(word)
    }).length
}
