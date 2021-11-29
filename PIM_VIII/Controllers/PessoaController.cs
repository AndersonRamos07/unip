using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using PIM_VIII.Models;

namespace PIM_VIII.Controllers;

public class PessoaController : Controller
{
    private readonly ILogger<PessoaController> _logger;

    public PessoaController(ILogger<PessoaController> logger)
    {
        _logger = logger;
    }
        public IActionResult Index()
    {
        return View();
    }
        public IActionResult CadastrarPessoa()
    {
        return View(new Pessoa());
    }
    public IActionResult GetPessoaDetails()
    {
        Pessoa pessoa = new Pessoa();
        pessoa.Nome = "Nome da Pessoa Aqui!";
        pessoa.CPF = 123456789;

        return View(pessoa);
    }
        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    } 
}