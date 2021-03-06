<?hh
namespace Titon\Common;

use Titon\Test\TestCase;

/**
 * @property \Titon\Common\FactoryStub $object
 */
class FactoryAwareTest extends TestCase {

    public function testFactory() {
        $instance1 = FactoryStub::factory();
        $this->assertInstanceOf('Titon\Common\FactoryStub', $instance1);

        $instance2 = FactoryStub::factory();
        $this->assertInstanceOf('Titon\Common\FactoryStub', $instance2);

        $this->assertNotSame($instance1, $instance2);
    }

    public function testRegistry() {
        $instance = FactoryStub::registry();

        $this->assertInstanceOf('Titon\Common\FactoryStub', $instance);
        $this->assertSame($instance, FactoryStub::registry());
    }

}

class FactoryStub {
    use FactoryAware;
}