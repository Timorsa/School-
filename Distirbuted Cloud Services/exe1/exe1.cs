using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace exe1.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class exe1 : ControllerBase
    {
        // GET api/values
        [HttpGet]
        public ActionResult<IEnumerable<string>> Get()
        {
            return new string[] { "value1", "value2" };
        }

        // GET api/exe1/5
        [HttpGet("{id}")]
        public ActionResult<string> Get(int id)
        {
            return "value";
        }

        // exersice 3 
        // assuming there are no unnecessary spaces and that str is not null
        // GET api/exe1/wordCount
        [HttpGet("wordCount")]
        public int wordCount(string str)
        {
            int wordCount = 0;
            if (str!=null)
            {
                foreach (char c in str)
                {
                    if (c == ' ')
                        wordCount++;
                }
            }
            return wordCount+1; //+1 --> last word isn't counted 
        }

        //exersice 6
        // GET api/exe1/repCount
		//assuming str!=null
        [HttpGet("repCount")]
        public int repCount(string str)
        {
            Dictionary<string, int> dictionary = new Dictionary<string, int>();
            string[] words = str.Split(' ');
            foreach (string word in words)
            {
                if (dictionary.ContainsKey(word)) 
                    dictionary[word] = dictionary[word] + 1; 
                else
                    dictionary[word] = 1;
            }
            return dictionary.Values.Max();

        }

        // exersice 12
        // GET api/exe1/cutEdges
        [HttpGet("cutEdges")]
        public string cutEdge(string str)
        {
            if (str!=null)
                return str.Substring(1, str.Length - 2);
            else return "The string you enterd is not valid";
        }

        // exersice 13
        // GET api/exe1/Calcs
        [HttpGet("Calcs")]
        public string Calcs(int a , int b)
        {
            if (b != 0)
                return (a + b) + ", " + (a - b) + ", " + (a * b) + ", " + (a / b);
            else return "Undefined ,can't devide by 0";
        }

        // exersice 17
        // GET api/exe1/pushIndex
        [HttpGet("pushIndex")]
        public string pushIndex(string str, int i)
        {
            if (str != null && i > 0 && i < str.Length)
                return str.Insert(i, i.ToString());
            else return "your string/index not valid";
        }

        // POST api/exe1
        [HttpPost]
        public void Post([FromBody] string value)
        {
        }

        // PUT api/exe1/5
        [HttpPut("{id}")]
        public void Put(int id, [FromBody] string value)
        {
        }

        // DELETE api/exe1/5
        [HttpDelete("{id}")]
        public void Delete(int id)
        {
        }
    }
}
