const puppeteer = require('puppeteer');
const fs = require('fs');

setTimeout(async () => {
    fs.unlink('text.txt', (err)=>{
        if (err) console.log('Error');
        else console.log('Unlink file')
    });
    const browser = await puppeteer.launch({ headless: false });
    const page = await browser.newPage();

    for (let x = 0; x < 190; x++) {
        await page.goto('https://www.timeanddate.com/weather/?low=c');
        let arr = await page.evaluate((index) => {
            let newindex = Math.floor(index / 2);
            let newindex2 = 0;
            if (index % 2 === 0){
                newindex2 = 0;
            }
            else if(index === 1){
                newindex2 = 4;
            }
            else{
                newindex2 = 4;
            }
            let element = document.querySelector("tbody").childNodes[newindex].childNodes[newindex2].innerText
            return element;
        }, x);
        fs.appendFileSync('text.txt', arr + ' ');
        let arr1 = await page.evaluate((index) => {
            let element = document.querySelectorAll(".rbi")[index].innerText
            return element;
        }, x);
        fs.appendFileSync('text.txt', arr1 + '\n');
    }

    await browser.close();
}, 100);
//document.querySelector("tbody").childNodes[0].childNodes[4].innerText
//document.querySelectorAll(".rbi")[1].innerText
//https://www.timeanddate.com/weather/?low=c